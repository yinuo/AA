/* memcpy/memmove */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char** argv)
{
    char *p = NULL;
    char *d = NULL;
    char s[] = "Hello Beijing City";
    
    p = (char *)malloc(strlen(s));      // Here have a bug, do you know why?
    if(p == NULL)
    {
        return (-1);	
    }
        
    d = (char *)malloc(strlen(s) + 1);
    if(d == NULL)
    {
        return (-1);	
    }
    
    printf("d addr is 0x%x \n", (int)d);
    
    printf("s string room is %d\n", sizeof(s));
    
    memcpy(p, s, strlen(s));            // Here have a bug, do you know why?
    memcpy(d, s, strlen(s) + 1);
    printf("memcpy p string is \"%s\" \n", p);
    printf("p string len is %d\n", strlen(p)); 
    
    memmove(d + 7, d, strlen(d));      // Here have a bug, do you know why?
    printf("memmove d string is \"%s\" \n", d);
    printf("d string len is %d\n", strlen(d));    
    
    printf("d addr is 0x%x \n", (int)d);
        
    free(d);    
    free(p);
    
    return 0;
}
