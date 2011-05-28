/* const */

#include <stdio.h>

/* Get Mul 2 Number */
int get_mul_2_num(const int num)
{
    int val = 0;
    
    //num = num << 1;     / error operation;
    val = num << 1;
    
    return (val);
}

/* main */
int main(int argc , char**argv)
{
    printf("calc 1*2 = %d\n", get_mul_2_num(1));
    printf("calc 2*2 = %d\n", get_mul_2_num(2));
    printf("calc 4*2 = %d\n", get_mul_2_num(4));
    printf("calc 8*2 = %d\n", get_mul_2_num(8));

    return 0;
}
