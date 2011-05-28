/* func_mem_r.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char** argv)
{
     char *p;

     p = (char *)malloc(8);
     if(p == NULL)
     {
         printf("malloc failure!\n");
         return -1;
     }
     
     memset(p, 0x61, 9);                 // Here have a bug, do you know why?
     p = (char *)realloc(p, 8912);
     memset(p + 9, 0x62, 8);
     printf("mem contents is %s \n", p);
     
     free(p);
     
     return 0;
}
