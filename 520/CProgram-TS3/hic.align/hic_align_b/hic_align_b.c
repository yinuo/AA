/* align optimize */

#include <stdio.h>
#include <stddef.h>

#include "hic_align_b.h"

int main()
{
	printf(" align_t4 using bytes = %d\n", sizeof(struct align_t4));
	printf(" a offset bytes  = %d  ", offsetof(struct align_t4, a));
	printf(" b offset bytes  = %d\n", offsetof(struct align_t4, b));
	printf(" c offset bytes  = %d  ", offsetof(struct align_t4, c));
	printf(" d offset bytes  = %d\n", offsetof(struct align_t4, d));	

	printf(" align_t5 using bytes = %d\n", sizeof(struct align_t5));
	printf(" a offset bytes  = %d  ", offsetof(struct align_t5, a));
	printf(" b offset bytes  = %d\n", offsetof(struct align_t5, b));
	printf(" c offset bytes  = %d  ", offsetof(struct align_t5, c));
	printf(" d offset bytes  = %d\n", offsetof(struct align_t5, d));
	
	printf(" align_t6 using bytes = %d\n", sizeof(struct align_t6));
	printf(" a offset bytes  = %d  ", offsetof(struct align_t6, a));
	printf(" b offset bytes  = %d\n", offsetof(struct align_t6, b));
	printf(" c offset bytes  = %d  ", offsetof(struct align_t6, c));
	printf(" d offset bytes  = %d\n", offsetof(struct align_t6, d));
		
	return 0;
}
