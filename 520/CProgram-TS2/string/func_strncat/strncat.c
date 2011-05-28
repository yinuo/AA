/* strncat.c */

#include <stdio.h>
#include <string.h>

int main(int argc, char**argv)
{
    char s[] = "Hello Nanjing";
    char d[] = "Hello Beijing City,";
    
    printf("%s \n", d);        
    strncat(d, s, sizeof(s) - 8);
    printf("%s \n", d);
    
    return 0;
}
