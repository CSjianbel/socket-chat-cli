#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

// Wrapper function for error handling
#define TRY(expr, condition, error_msg) \
  do { \
    if ((expr) condition) { \
      perror(error_msg); \
      exit(EXIT_FAILURE); \
    } \
  } while (0)


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
  printf("Connecting to server at port: %d ...\n", port_number);
  TRY(connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)), < 0, "Connection Failed!\n");
  printf("Connected successfully!\n");

  // message storage
  char buffer[256];
  memset(buffer, 0, 256);

  //send message to server
  printf("< ");
  fgets(buffer, 255, stdin);
  printf("Sending message to server ...\n");

  int n;
  TRY(n = send(client_socket, buffer, strlen(buffer), 0), < 0, "Sending Failed!\n");
  printf("Message sent successfully!\n");
  printf("Waiting for reply ...\n");

   // receive server reply
  memset(buffer, 0, 256);
  TRY(n = recv(client_socket, buffer, 255, 0), < 0, "Receiving Failed!\n");
  printf("Server reply: %s", buffer);

  close(client_socket);

  return 0;
}
