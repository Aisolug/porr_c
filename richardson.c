#include <stdio.h>
#include <stdlib.h>
#include "richardson.h"
#include <math.h>

double* resultRichardson(richardson rich, int* test, int loop, double* richardson){

	double gamma = 0.003;	
	rich.input = (double *) calloc(rich.size, sizeof(double));
	if (loop == 1){
		
		int z;
		for (z = 0; z < rich.size; z++){
			rich.input[z] = 2.0;	
		}
	}
	else{
		int z;
		for (z = 0; z < rich.size; z++){
			rich.input[z] = richardson[z];	
		}
	}
	rich.fun = (double *) calloc(rich.size, sizeof(double));
        rich.sum = (double *) calloc(rich.size, sizeof(double));
	int i;
        for (i = 0; i < rich.size; i ++){
		int k;            
		for (k = 0; k < rich.size; k ++){
                	if(i != k){
                    		rich.sum[i] += (double)(test[i*rich.size+k])*rich.input[k];
				
				
                	}
            	}
        }
	
	int n;
        for (int n = 0; n < rich.size; n++){
        	rich.fun[n] = rich.sum[n] + (double)test[n+n*rich.size]*pow(rich.input[n],3.0);
		rich.fun[n] = rich.input[n] - gamma*rich.fun[n];
	
        }
	free(rich.input);	
	free(rich.sum);
	return rich.fun;
}

