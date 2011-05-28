/* strlen.c */

#include <stdio.h>
#include <string.h>

int main(int argc, char**argv)
{
    char s[] = "Hello Beijing Haidian";

    printf("<%s> string length is %d\n", s, strlen(s));

    return 0;
}
