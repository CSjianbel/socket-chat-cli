
#ifndef MESSAGE_H
#define MESSAGE_H

#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>

#define BUFFER_SIZE 256

void send_message(int socket, char *name);
void receive_message(int socket, char *name);

#endif