/* assert */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

double add_calc(double *db1, double *db2)
{
		assert(db1 != NULL);
	  assert(db2 != NULL);
	  
    return (*db1 + *db2);
}

int main(int argc, char** argv)
{
	  double db1 = 10;
	  double db2 = 15;
	  double result = 0;
	  
	  result = add_calc(&db1, &db2);
	  
    printf(" %f + %f = %f \n", db1, db2, result); 
    
	  result = add_calc(&db1, NULL);
	  
    printf(" %f + NULL = %f \n", db1, result); 
    
    return 0;
}
