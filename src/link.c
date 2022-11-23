#include "../inc/link.h"

void sysError(const char *str) 
{
    perror(str);
    exit(1);
}