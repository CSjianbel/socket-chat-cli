#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#include "error.h"
#include "memory.h"
#include "message.h"

int main(int argc, char* argv[]) {
  // Check if the passed arguments is valid
  TRY(argc, < 3, "Usage: ./client host_name port_number\n");
  char* host_name = argv[1];
  int port_number = atoi(argv[2]);
 
  // create a socket
  printf("Client starting ...\n");
  int client_socket;
  TRY(client_socket = socket(AF_INET, SOCK_STREAM, 0), < 0, "Error Creating socket!\n");
  printf("Socket created successfully!\n");
  
  // find host
  printf("Looking for host %s ...\n", host_name);
  struct hostent* server;
  TRY(server = gethostbyname(host_name), == NULL, "Host not found!\n");
  printf("Host found!\n");
  
  // establish connection to server
  struct sockaddr_in server_addr;
  memset((char*)&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port_number);
  memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
  
  // try to connect to the server
  TRY(connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)), < 0, "Connection Failed!\n");
  printf("Connected to Server!\n\n");
  printf("Start chatting:\n\n");

  // Open the shared memory object
  int shm_fd = open_shared_memory();

  void *shm_ptr = mmap(NULL, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

  // 0 - Server can send a message
  // 1 - Client can send a message
  // Initially the server can send a message

  // send and receive message to and from server
  int pid = fork();
  while (1) {
    if (pid == 0) {
      // Verify if client's turn to send a message
      if (strcmp((char*) shm_ptr, "0") == 0) {
        // Send the message
        send_message(client_socket, "server");
        // Set shared memory to 1
        sprintf((char*) shm_ptr, "%s", "1\0");
      }
    } else {
      receive_message(client_socket, "server");
    }
  }

  printf("Closing connection ...\n");
  close(client_socket);
  
  return 0;
}
