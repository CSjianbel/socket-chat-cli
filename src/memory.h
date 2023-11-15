#ifndef MEMORY_H 
#define MEMORY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define SHM_NAME "socketchat"
#define SIZE 1024

int init_shared_memory();
int open_shared_memory();

#endif