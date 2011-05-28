/* align optimize */

#include <stdio.h>
#include <stddef.h>

#include "hic_align_a.h"

int main()
{
	printf(" align_t1 using bytes = %d\n", sizeof(struct align_t1));
	printf(" a offset bytes  = %d  ", offsetof(struct align_t1, a));
	printf(" b offset bytes  = %d\n", offsetof(struct align_t1, b));
	printf(" c offset bytes  = %d  ", offsetof(struct align_t1, c));
	printf(" d offset bytes  = %d\n", offsetof(struct align_t1, d));	

	printf(" align_t2 using bytes = %d\n", sizeof(struct align_t2));
	printf(" c offset bytes  = %d  ", offsetof(struct align_t2, c));
	printf(" b offset bytes  = %d\n", offsetof(struct align_t2, b));
	printf(" a offset bytes  = %d  ", offsetof(struct align_t2, a));
	printf(" d offset bytes  = %d\n", offsetof(struct align_t2, d));
	
	printf(" align_t3 using bytes = %d\n", sizeof(struct align_t3));
	printf(" a offset bytes  = %d  ", offsetof(struct align_t3, a));
	printf(" b offset bytes  = %d\n", offsetof(struct align_t3, b));
	printf(" c offset bytes  = %d  ", offsetof(struct align_t3, c));
	printf(" d offset bytes  = %d\n", offsetof(struct align_t3, d));
		
	return 0;
}
