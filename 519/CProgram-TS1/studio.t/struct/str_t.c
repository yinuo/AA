#include <stdio.h>
#include <stdlib.h>
#include "stru_t.h"

int main(int argc,char **argv){
	a_t *b;
	b = malloc(sizeof(a_t));
	char s_name[]="abcd";

	b->age = 200;
	b->name = s_name;

	printf("%d %s\n",b->age,(char *)b->name);	
		
	free (b);
        return 0;
}
