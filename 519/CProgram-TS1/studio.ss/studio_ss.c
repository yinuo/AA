/* studio */

#include <stdio.h>

int main( int argc, char ** argv)
{
     char ch_s1[8] = "hello"; 
     char ch_s2[] = "hello";
     char ch_s3[] = {'h', 'e', 'l', 'l', 'o', '\0'};
     const char* ch_s4 = "hello";
     
     ch_s1[0] = 'H';
     ch_s2[0] = 'H';
     printf(" %s s1 \n", ch_s1);
     printf(" %s s2 \n", ch_s2); 
     printf(" %s s3 \n", ch_s3); 
     printf(" %s s4 \n", ch_s4);
      
     return 0;
}
