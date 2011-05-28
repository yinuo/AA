/* array */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int iloop = 0;
    int a[1024] ={0};
       
    for(iloop=0; iloop <1024; iloop++)    
	  {
	      a[iloop] = 0x55aa;
	  }
	  printf("a[1023] = 0x%x \n", a[1023]);
    printf("a[1024] = 0x%x \n", a[1024]);
	  
    for(iloop=0; iloop <=1024; iloop++)
	  {
	      a[iloop] = 0xaa55;
	  }
	  printf("a[1023] = 0x%x \n", a[1023]);
    printf("a[1024] = 0x%x \n", a[1024]);
    
    return 0;
}
