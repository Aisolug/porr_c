#include <stdio.h>
#include <stdlib.h>
#include "testFun.h"
#include "jacobi.h"
#include "richardson.h"

int main() {

	funkcja pierwsza;
	jacobi jacobi;
	richardson rich;
	
	int n = 4;
	//pierwsza.exponent = 4;
	pierwsza.nr = 1;

	pierwsza.size = jacobi.size = rich.size = n;
	
/// Tworzenie funkcji testowej ///

	int *vector;
	if (pierwsza.nr = 1){
		vector = createTestF1(pierwsza);
		free(pierwsza.test);
	}

/// iteracyjne wyniki dla Jacobiego i Richardsona ///

	double* jacobian;
	double* richardson;
	int loop = 1;
	for (loop; loop < 50; loop++){
		jacobian = resultJacobi(jacobi, vector, loop, jacobian);
		free(jacobi.fun);

		richardson = resultRichardson(rich, vector,loop, richardson);
		free(rich.fun);
	}

///////////////// WYSWIETLANIE WYNIKOW /////////////////
	
	printf("\n\nMacierz funkcji testowej\n");

	int j;
	for (j = 0; j < n*n; j ++){
		if (j%n == 0 ) printf("\n");		
		printf("%d\t",vector[j]);
	}

	printf("\n\n\nWyniki dla jacobiego\n");
	int i;
	for (i = 0; i < n; i ++){		
		printf("%f\t",jacobian[i]);

	}

	printf("\n\n\nWyniki dla richardsona\n");
	int h;
	for (h = 0; h < n; h ++){		
		printf("%f\t",richardson[h]);

	}
}
