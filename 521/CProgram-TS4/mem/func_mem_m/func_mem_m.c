/* func_mem_s.c */

#include <stdio.h>
#include <stdlib.h>

//char *p = (char *)malloc(1024);

int main (int argc, char** argv)
{
    char *p = (char *)malloc(1024);

    if(p != NULL)
    {
        printf("malloc at  address: 0x%x\n", (int)p);
	free(p);
        return 0;                        // Here maybe have a bug, do you know why?
    }
    else
    {
        printf("malloc failure!\n");
    }
    free(p);
     
    return 0;
}
