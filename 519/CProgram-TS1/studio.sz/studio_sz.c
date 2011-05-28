/* studio */

#include <stdio.h>
#include <string.h>

int main( int argc, char ** argv)
{
     char ch_s1[8] = "hello";
     char ch_s2[] = "hello";
     char ch_s3[] = {'h', 'e', 'l', 'l', 'o', '\0'};
     
     printf(" s1 length (strlen) is %d \n", strlen(ch_s1));
     printf(" s1 length (sizeof) is %d \n", sizeof(ch_s1));
     printf(" s2 length (strlen) is %d \n", strlen(ch_s2));
     printf(" s2 length (sizeof) is %d \n", sizeof(ch_s2));
     printf(" s3 length (strlen) is %d \n", strlen(ch_s3));
     printf(" s3 length (sizeof) is %d \n", sizeof(ch_s3));
     
     return 0;
}
