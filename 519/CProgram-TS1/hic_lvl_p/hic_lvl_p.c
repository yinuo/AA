/* level enhance */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	  int dw = 0;
	  int hi = 0x5555;
	  int lo = 0xaaaa;	  	  
	  
    dw = hi << 16 + lo;        // dw = hi << (16 + lo);
    printf(" hi(0x%x) << 16 + lo(0x%x) = 0x%x \n", hi, lo, dw);
    
    dw = (hi << 16) + lo;
    printf(" (hi(0x%x) << 16) + lo(0x%x) = 0x%x \n", hi, lo, dw);
        
    return 0;
}
