#include "../inc/link.h"

void sysError(const char *str) 
{
    perror(str);
    exit(1);
}

// free the pointer
void freePointer(void *pointer) 
{
    if (pointer != NULL)
    {
        free(pointer);
        pointer = NULL;
    }
}