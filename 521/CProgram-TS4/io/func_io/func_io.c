/* function */

#include <stdio.h>

int main( int argc, char ** argv)
{
    char ch = 0;
    char ch_s[128];
    int  d32 = 0;
    
    scanf("%c", &ch); 
    printf(" scanf() get char is %c \n", ch);

    scanf("%d", &d32);
    printf(" scanf() get int is %d \n", d32);
    
    scanf("%s", ch_s); 
    printf(" scanf() get string is %s \n", ch_s);
    
    return 0;
}
