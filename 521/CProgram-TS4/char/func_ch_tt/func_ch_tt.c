/* function */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h> 

int main( int argc, char ** argv)
{
    char ch = 0, ch_u = 0;
    printf("Press a key, Then press 'Enter' key !\n");
    ch = getchar();
    if((ch >= 0x41) && (ch <= 0x5A))
    {
        ch = tolower(ch);
    }
    ch_u = toupper(ch);
    printf("char low is %c  and upper is %c\n",  ch, ch_u);
    return 0;
}
