/* align optimize .h */

#ifndef _HIC_ALIGN_H_
#define _HIC_ALIGN_H_

struct align_t1
{
   char  a;
	 short b;
	 int   c;
	 char  d;
};

struct align_t2
{
	 int   c;
	 short b;
	 char  a;
	 char  d;
};

struct align_t3
{
   char  a;
	 short b;
	 int   c;
	 char  d;
}__attribute__((packed));

#endif /* _HIC_ALIGN_H_ */
