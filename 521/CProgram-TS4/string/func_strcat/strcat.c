/* strcat.c */

#include <stdio.h>
#include <string.h>

int main(int argc, char**argv)
{
    char s[] = "Hello Nanjing";
    char d[] = "Hello Beijing City,";
    
    printf("%s \n", d);        
    strcat(d, s);
    printf("%s \n", d);
    
    return 0;
}
