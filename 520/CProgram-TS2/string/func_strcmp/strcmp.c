/* strcmp.c */

#include <stdio.h>
#include <string.h>

int main(int argc, char**argv)
{
    char s1[] = "Hello Beijing Haidian";
    char s2[] = "Hello Beijing";
    int ret = 0;
    
    ret = strcmp(s1, s2);
    if(!ret)
    {
        printf("<%s> string and string <%s> are equal\n", s1, s2);
    }
    else
    {
        if(ret < 0)
        {
           printf("<%s> string less than string <%s>\n", s1, s2);
        }
        else
        {
           printf("<%s> string greater than string <%s>\n", s1, s2);
        }
    }
    return 0;
}
