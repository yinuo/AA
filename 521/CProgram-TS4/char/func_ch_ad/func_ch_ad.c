/* function */

#include <stdio.h>
#include <ctype.h>

int main( int argc, char ** argv)
{
    char ch = 0;

    printf("Press a key, Then press 'Enter' key !\n");
    ch = getchar();
    printf("%c: %s a alpha \n", ch, isalpha(ch) ? "is":"not"); 
    printf("%c: %s a digital \n", ch, isdigit(ch) ? "is":"not"); 

    return 0;
}
