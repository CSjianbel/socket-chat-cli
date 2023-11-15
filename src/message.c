#include "message.h"
#include "error.h"

void receive_message(int client_socket, char *name) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    // receiving message from server
    int bytes_received;
    TRY(bytes_received = recv(client_socket, buffer, 255, 0), < 0, "Receiving Failed!\n");

    // move cursor to the beginning of the line and clear the line
    printf("\033[1G\033[2K");

    // display the received message
    printf("[%s] > %s", name, buffer);

    // prompt for a new input
    printf(">> ");
    fflush(stdout);
}

void send_message(int client_socket, char *name) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    // move cursor to the beginning of the line and clear the line
    printf("\033[1G\033[2K");

    // prompt for user input
    printf(">> ");
    fgets(buffer, 255, stdin);

    // sending message to server
    int bytes_sent;
    TRY(bytes_sent = send(client_socket, buffer, strlen(buffer), 0), < 0, "Sending Failed!\n");
}