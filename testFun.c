#include <stdio.h>
#include <stdlib.h>
#include "testFun.h"

int x;

int* complementMatrix(funkcja fun){
    	
	int i;    
        for (i = 1; i < fun.size; i ++){
		int k;            
		for (k = 0; k < fun.size; k ++){
	        	if(k < i){
	                    fun.test[i*fun.size+k] = fun.test[k*fun.size + i];    
                	}
            	}
        }
	return fun.test;
}

int* derivativeMatrix(funkcja fun){
                
		
	int i;
        for (i = 0; i < fun.size; i++){
            fun.test[i*(1+fun.size)] = fun.test[i*(1+fun.size)]*4;
        }

	return fun.test;
}
	
int* createTestF1(funkcja fun){
	
	fun.test = (int *) calloc(fun.size*fun.size, sizeof(int));
	int coefficiency[5] = {7,20,5,-9,-10};
	x = 3;
	int j;

	for (j = x-1; j< fun.size; j++){
		int i;
            	for (int i = 1; i < x; i++){
                	fun.test[(j-i)*fun.size + j-i] += coefficiency[x-1-i];
           	}
            	fun.test[j+j*fun.size] += j*coefficiency[2];
            	
		for (int i = 0; i < x-1; i++){
                	fun.test[(j-2)*fun.size +j-i] = (j+1)*coefficiency[x*2-2-i];
 	        }  
        }
	fun.test[0] += 5; //zapewniona dominacja
	fun.test = complementMatrix(fun);
	fun.test = derivativeMatrix(fun);
	return fun.test;
}
     


