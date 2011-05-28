/* function */

#include <stdio.h>
#include <ctype.h>

int main( int argc, char ** argv)
{
    char ch = 0;

    printf("Press a key, Then press 'Enter' key !\n");
    ch = getchar();
    printf("%c: %s a lower(letter) \n", ch, islower(ch) ? "is":"not"); //low
    printf("%c: %s a upper(letter) \n", ch, isupper(ch) ? "is":"not"); //upper

    return 0;
}
