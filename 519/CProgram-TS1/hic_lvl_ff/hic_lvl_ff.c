/* #define DATA_TYPE */

#include <stdio.h>
#include <stdlib.h>

#define FLOAT_T

int main(int argc, char** argv)
{
#ifdef FLOAT_T	
    float axis_x_cn = 0.0;
    float axis_y_cn = 100000000000000000000000000000000000.0; // 36
    float axis_z_cn = 0.000000000000000000000000000000000001; // 36
    
    float axis_x_en = 0.333333333333333333333333333;
    float axis_y_en = 1000000000000000000000000000000000000.0; // 38
    float axis_z_en = 0.0000000000000000000000000000000000001; // 38
    
    float axis_x_us = (1/3);   
    float axis_y_us = 1000000000000000000000000000000000000000.0;  // 39
    float axis_z_us = 0.000000000000000000000000000000000000000000001; // 44
    
#else    
    float axis_z_us_a = 0.000000000000000000000000000000000000000000001; // 44
    float axis_z_us_b = 0.0000000000000000000000000000000000000000000001; // 45    
    float axis_z_us_c = 4.000001;  // 6
    float axis_z_us_d = 4.0000001;  // 7
#endif
    
#ifdef FLOAT_T
    printf("axis_x_cn is %.48f\n", axis_x_cn);
    printf("axis_y_cn is %48f\n", axis_y_cn);
    printf("axis_z_cn is %.48f\n", axis_z_cn);
    
    printf("axis_x_en is %.48f\n", axis_x_en);
    printf("axis_y_en is %48f\n", axis_y_en);
    printf("axis_z_en is %.48f\n", axis_z_en);
      
    printf("axis_x_us is %.48f\n", axis_x_us);
    printf("axis_y_us is %48f\n", axis_y_us);
    printf("axis_z_us is %.150f\n", axis_z_us);
#else        
    printf("axis_z_us_a is %.150f\n", axis_z_us_a);
    if(axis_z_us_a == 0) 
    {
        printf("axis_z_us_a == 0\n");	
    }
    else
    {
        printf("axis_z_us_a > 0\n");	    	
    }  
    printf("axis_z_us_b is %.150f\n", axis_z_us_b);
    if(axis_z_us_b == 0) 
    {
        printf("axis_z_us_b == 0\n");	
    }
    else
    {
        printf("axis_z_us_b > 0\n");	    	
    }   
    printf("axis_z_us_c is %.48f\n", axis_z_us_c);
    if(axis_z_us_c == 4) 
    {
        printf("axis_z_us_c == 4\n");	
    }
    else
    {
        printf("axis_z_us_c > 4\n");	    	
    }     
    printf("axis_z_us_d is %.48f\n", axis_z_us_d); 
    if(axis_z_us_d == 4) 
    {
        printf("axis_z_us_d == 4\n");	
    }
    else
    {
        printf("axis_z_us_d > 4\n");	    	
    }                           
#endif
	  return 0;
}
