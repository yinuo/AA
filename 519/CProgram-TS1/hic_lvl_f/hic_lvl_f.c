/* strcpy */

#include <stdio.h>
#include <string.h>
 
int main(int argc, char**argv)
{
	  char s[] = "Hello Nanjing";
    char d[] = "Hello Beijing City";
    char m[] = "Hello Shanghai City";
    int s_len = 0;
    int r_len = 0;    
    
    printf("<0> %s\n", s);
    strncpy(s, m, (strlen(s) <= strlen(m)) ? strlen(s): strlen(m));
    printf("<0> %s\n", s);
        
    s_len = strlen(s);
    printf("<0> s string len is %d\n", s_len);
    r_len = sizeof(s);
    printf("<0> sizeof(s) len is %d\n", r_len);
    
    printf("\n<1> %s\n", s);
    strcpy(s, d);              // Here have a bug , do you now why?
    printf("<1> %s\n", s);
    
    s_len = strlen(s);
    printf("<1> s string len is %d\n", s_len);
    r_len = sizeof(s);
    printf("<1> sizeof(s) len is %d\n", r_len);
    
    printf("\n<2>%s\n", s);
    strncpy(s, m, (strlen(s) <= strlen(m)) ? strlen(s): strlen(m));
    printf("<2>%s\n", s);
    
    return 0;
}
