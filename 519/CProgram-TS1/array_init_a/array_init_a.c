/* array */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char** argv)
{
    char s[] = "Hello Beijing City";
    char c[64] = {0x62};
    int w2[][64] = {{0x00}, {0x32}, {0x48}, {0x64}};    
    
    printf("array s[0] is %c \n", s[0]);
    printf("array s[17] is %c \n", s[17]);
    printf("array c[0] is 0x%x \n", c[0]);
    printf("array c[63] is 0x%x \n", c[63]);
    printf("array w2[0][0] is 0x%x \n", w2[0][0]);
    printf("array w2[3][0] is 0x%x \n", w2[3][0]);
    
    return 0;
}
