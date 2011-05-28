/* strchr.c */

#include <stdio.h>
#include <string.h>

int main(int argc, char**argv)
{
    char s[] = "Hello Beijing City";
    char *p;
        
    p = strchr(s,'e');//连续查找同一个字符，应该？
    if(p)
    {
      printf("<%s> start <%c> string is %s \n", s, 'e', p);
    }
    p = strchr(p+1,'e');
    if(p)
    {
      printf("<%s> start <%c> string is %s \n", s, 'e', p);
    }
    else
    {
        printf("Not Found!");
    }
    
    return 0;
}
