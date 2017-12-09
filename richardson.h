#ifndef RICHARDSON_H
#define RICHARDSON_H

typedef struct tag_richardson{
	
	int size;
	double *input; 
	double *sum;
	double *fun;

}richardson;

double* resultRichardson(richardson rich, int* test, int loop, double* richardson);

#endif
