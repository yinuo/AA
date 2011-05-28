/* strncpy.c */

#include <stdio.h>
#include <string.h>

int main(int argc, char**argv)
{
    char s[] = "Hello Nanjing";
    char d[] = "Hello Beijing City";
    char m[] = "Hello Shanghai City";
    char *p = strdup(m);
    
    strncpy(d, s, strlen(s));
    printf("%s\n", d);
    
    printf("%s\n", p);
    strncpy(p, d, strlen(s));    
    printf("%s\n", p);
        
    return 0;
}
