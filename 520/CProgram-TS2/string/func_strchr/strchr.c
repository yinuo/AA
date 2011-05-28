/* strchr.c */

#include <stdio.h>
#include <string.h>

int main(int argc, char**argv)
{
    char s[] = "Hello Beijing City";
    char *p;
        
    p = strchr(s,'B');
    if(p)
    {
      printf("<%s> start <%c> string is %s \n", s, 'B', p);
    }
    else
    {
        printf("Not Found!");
    }
    
    return 0;
}
