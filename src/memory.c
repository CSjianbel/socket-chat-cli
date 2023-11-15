#include "memory.h"

int init_shared_memory() {
    // Create the shared memory object
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    // Configure size of shared memory
    ftruncate(shm_fd, SIZE);
    return shm_fd;
}

int open_shared_memory() {
    // Open the shared memory object
    return shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
}
