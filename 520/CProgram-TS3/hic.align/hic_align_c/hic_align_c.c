/* align optimize */

#include <stdio.h>
#include <stddef.h>

#include "hic_align_c.h"

int main()
{
	printf(" align_t7 using bytes = %d\n", sizeof(struct align_t7));
	printf(" a offset bytes  = %d  ", offsetof(struct align_t7, a));
	printf(" b offset bytes  = %d\n", offsetof(struct align_t7, b));
	printf(" c offset bytes  = %d  ", offsetof(struct align_t7, c));
	printf(" d offset bytes  = %d\n", offsetof(struct align_t7, d));	

	printf(" align_t8 using bytes = %d\n", sizeof(struct align_t8));
	printf(" a offset bytes  = %d  ", offsetof(struct align_t8, a));
	printf(" b offset bytes  = %d\n", offsetof(struct align_t8, b));
	printf(" c offset bytes  = %d  ", offsetof(struct align_t8, c));
	printf(" d offset bytes  = %d\n", offsetof(struct align_t8, d));
	
	printf(" align_t9 using bytes = %d\n", sizeof(struct align_t9));
	printf(" a offset bytes  = %d  ", offsetof(struct align_t9, a));
	printf(" b offset bytes  = %d\n", offsetof(struct align_t9, b));
	printf(" c offset bytes  = %d  ", offsetof(struct align_t9, c));
	printf(" d offset bytes  = %d\n", offsetof(struct align_t9, d));
		
	return 0;
}
