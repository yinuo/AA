/* endian type get */

#include <stdio.h>

int main(int argc, char**argv)
{
    int edata = 1;
    
    if(*(char *)&edata == 1)
    {
        printf("little-endian\n");
    }
    else
    {
        printf("big-endian\n");
    }
    
    return 0;
}
