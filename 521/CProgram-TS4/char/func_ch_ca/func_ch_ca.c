/* function */

#include <stdio.h>
#include <ctype.h>

int main( int argc, char ** argv)
{
    char ch = 0;

    printf("Press a key, Then press 'Enter' key !\n");
    ch = getchar();
    printf("%c: %s a cntrl (letter) \n", ch, iscntrl(ch) ? "is":"not");// control character 
    printf("%c: %s a ascii (letter) \n", ch, isascii(ch) ? "is":"not"); //ascll character

    return 0;
}
