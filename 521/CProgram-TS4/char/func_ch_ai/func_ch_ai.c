/* function */

#include <stdio.h>
#include <ctype.h>

int main( int argc, char ** argv)
{
    char ch = 0;

    printf("Press a key, Then press 'Enter' key !\n");
    ch = getchar();
    printf("%c: %s a alpha or digital \n", ch, isalnum(ch) ? "is":"not"); //NO. and chracter
    printf("%c: %s a space \n", ch, isspace(ch) ? "is":"not"); //space

    return 0;
}
