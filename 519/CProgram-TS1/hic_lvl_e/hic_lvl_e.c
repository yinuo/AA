/* == and = */

#include <stdio.h>

int main (int argc, char** argv)
{
     int data = 0;
     
#if 1
     printf("@a0@: data = %f\n", (float)data);
        
     data = 1; 
     if(1 == data)
     {
         printf("@a1@: data = %d\n", data);
     }
     
     data = 2;
     printf("@a2@: data = %d\n", data);
     
#else
     printf("@b0@: data = %f\n", (float)data);
        
     data = 1;
     if(data = 2)
     {
         printf("@b2@: data = %d\n", data);
     }
     
     data == 3;
     printf("@b3@: data = %d\n", data);
#endif

     return 0;
}
