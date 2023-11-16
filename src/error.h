#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>
#include <stdlib.h> 

// Wrapper function for error handling
#define TRY(expr, condition, error_msg) \
  do { \
    if ((expr) condition) { perror(error_msg); \
      exit(EXIT_FAILURE); \
    } \
  } while (0)

#endif