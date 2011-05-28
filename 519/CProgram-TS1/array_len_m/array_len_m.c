/* array */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char** argv)
{
    char c[2][64] = {{0}, {0}};
    int w[][64] = {{0}, {0}, {0}, {0}};
    long long ll[][64] = {{0}, {0}};
    
    printf("array c[64] length is %d \n", sizeof(c));
    printf("array w[64] length is %d \n", sizeof(w));
    printf("array ll[64] length is %d \n", sizeof(ll));            
    
    printf("array c[64] start address is 0x%x (0x%x) \n", (int)c, (int)&c[0][0]);
    printf("array w[64] start address is 0x%x (0x%x) \n", (int)w, (int)&w[0][0]);
    printf("array ll[64] start address is 0x%x (0x%x)\n", (int)ll, (int)&ll[0][0]); 
    
    return 0;
}
