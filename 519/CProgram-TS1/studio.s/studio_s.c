/* studio */

#include <stdio.h>

int main( int argc, char ** argv)
{  
    switch(argc)
    {
         case 1:
              printf("argv %d (param 2) last string is %s \n", argc, (char*)argv[0]);
            break;       	          
         case 2:
              printf("argv %d (param 2) last string is %s \n", argc, (char*)argv[1]);
            break;

    }
    return 0;
}
