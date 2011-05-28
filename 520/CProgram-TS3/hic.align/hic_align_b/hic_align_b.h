/* align optimize .h */

#ifndef _HIC_ALIGN_H_
#define _HIC_ALIGN_H_

struct align_t4
{
   char* a;
	 short b;
	 int   c;
	 char  d;
};

struct align_t5
{
   char* a;
	 short b;
	 int   c;
	 char  d;
}__attribute__((packed));

struct align_t6
{
	 struct align_t4 a;
	 short b;
	 struct align_t5 c;
	 char  d;
}__attribute__((packed));

#endif /* _HIC_ALIGN_H_ */
