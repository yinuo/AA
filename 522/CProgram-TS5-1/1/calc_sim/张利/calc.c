#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define PI 3.141592653
/* add */
double calc_add(double a1,double a2)
{
    double result = 0;
    
    result = a1 + a2;
    
    return result;
}

/* sub */
double calc_sub(double s1, double s2)
{
    double result = 0;
    
    result = s1 - s2;
    
    return result;
}

/*mul*/
double calc_mul(double m1, double m2)
{
    double result = 0;
  
    result = m1 * m2;

    return result;
}

/*div*/
double calc_div(double d1, double d2)
{
    double result = 0;

    result = d1 / d2;

    return result;
}

/*pi*/
double calc_pi()
{
   return PI;
}

/*sin*/
double calc_sin(double si)
{
   double result;
   result = sin(si);
   return result;
}

/*cos*/
double calc_cos(double ci)
{
   double result;
   result = cos(ci);
   return result;
}

/*tan*/
double calc_tan(double ti)
{
   double result;
   result = tan(ti);
   return result;
}

/*fabs*/
double calc_fabs(double fi)
{
   double result; 
   result = fabs(fi);
   return result;
}

/*exp*/
double calc_exp(double ei)
{
   double result;
   result = exp(ei);
   return result;
}

/*ln*/
double calc_ln(double li)
{
   double result;
   result = log(li);
   return result;
}

/*log10*/
double calc_log10(double lli)
{
   double result;
   result = log10(lli);
   return result;
}

/*pow*/
double calc_pow(double p1,double p2)
{
   double result;
   result = pow(p1,p2);
   return result;
}

/*rand*/
double calc_rand()
{
   double result;
   srand((int)time(0));
   result = rand();
   return result;
}

int main(int argc,char **argv){
	
	unsigned int calc_mod = 0;
	double idata  = 0;
        double kdata  = 0;
        double result = 0;
	
	

	if(argc <2){
	
	 printf("enter cmd numbers must >= 2!!\n");
	 return -1;
}
       
       if(2 == argc){
  		argv++;	
		calc_mod = atoi(*argv);

	switch(calc_mod){
		case 5:
			printf("Calc PI is %f\n",calc_pi());
			break;

		case 14:
			result = calc_rand();
			printf("Calc rand result is %f\n", result);
			break;
		default:
			printf("Input abnormally\n");
			break;
}
}
	if(3 == argc){
		argv++;	
		calc_mod = atoi(*argv);
		argv++;    
            	idata = atof(*argv);
	switch(calc_mod){
		case 6:
			result = calc_sin((double) idata);
			printf("Calc sin (%f) result is %f\n",idata,result);			
				break;
		case 7: 
			result= calc_cos((double) idata);
			printf("Calc cos (%f) result is %f\n",idata,result);
				break;
		case 8:
			if(PI/2 == idata ||-PI/2 == idata){
				printf("Input abnormally\n");
				break; 			
			}
			result = calc_tan((double) idata);
			printf("Calc tan (%f) result is %f\n",idata,result);				
				break;
		case 9:
			result = calc_fabs((double) idata);
			printf("Calc tan (%f) result is %f\n",idata,result);
				break;
		case 10:
			result = calc_exp((double) idata);
			printf("Calc exp (%f) result is %f\n",idata,result);
				break;
		case 11:
			if(idata <= 0){
				printf("Input abnormally\n");
				break;
			}
			result = calc_ln((double) idata);
			printf("Calc ln (%f) result is %f\n",idata,result);
				break;
		case 12:
			if(idata <= 0){
				printf("Input abnormally\n");
				break;
			}
			result = calc_log10((double) idata);
			printf("Calc log10 (%f) result is %f\n",idata,result);
				break;	
		default:
			printf("Input abnormally\n");
				break;
}
}

	if(4 == argc){
		argv++;	
		calc_mod = atoi(*argv);
		argv++;    
            	idata = atof(*argv);
		argv++;
  		kdata = atof(*argv); 
	switch(calc_mod){
		case 1:
			result = calc_add(idata, kdata);   
	                printf("Calc add (%f + %f) result is %f\n", idata, kdata, result); 
			break;
		case 2:
  			result = calc_sub(idata, kdata);
 	                printf("Calc sub (%f - %f) result is %f\n", idata, kdata, result);     	    	    
    	 			break;
		case 3: 
			result = calc_mul(idata,kdata);
			printf("Calc mul (%f * %f) result is %f\n", idata, kdata, result);
				break;
		case 4:
			if(0 == kdata){
				printf("Input abnormaly\n");
				break;
			}	
			result = calc_div(idata,kdata);
			printf("Calc div (%f / %f) result is %f\n", idata, kdata, result);
		case 13:
			result = calc_pow(idata,kdata);
			printf("Calc pow (%f / %f) result is %f\n", idata, kdata, result);
				break;
		default:
			printf("Input abnormally\n");
				break;
} 
}
  
return 0;

}
