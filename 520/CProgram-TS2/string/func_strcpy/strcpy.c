/* strcpy.c */

#include <stdio.h>
#include <string.h>

int main(int argc, char**argv)
{
    char s[] = "Hello Nanjing";
    char d[] = "Hello Beijing City";
    char m[] = "Hello Shanghai City";
        
    printf("%s\n", d);    
    strcpy(d, s);
    printf("%s\n", d);
    
    printf("%s\n", s);
    strcpy(s, m);              // Here have a bug , do you now why? 
    printf("%s\n", s);
        
    return 0;
}
