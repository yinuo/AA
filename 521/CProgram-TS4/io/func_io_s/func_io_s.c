/* function */

#include <stdio.h>

int main( int argc, char ** argv)
{
    char ch = 0;                // Here have a bug, Do you know why?

    if((ch = getchar())  !=  EOF)
    {
        putchar(ch);
        putchar('\n');
    }

    return 0;
}
