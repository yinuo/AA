/* func_mem_c.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char** argv)
{
    char s[] = "Hello Beijing City";
    char *d;
    
    d = malloc(128);
    
    memcpy(d, s, strlen(s));
    printf("memcpy d string is %s\n", d);
    
    memmove(d, d + 6, strlen(d) - 6);
    printf("no.1: memmove d string is %s\n", d);
    
    memmove(d + 7, d, strlen(d));            // Here have a bug, do you know why?
    printf("no.2: memmove d string is %s\n", d);
    
    free(d);
    
    return 0;
}
