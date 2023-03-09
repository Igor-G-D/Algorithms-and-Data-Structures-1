#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "library.h"

int main( ) {

	int degraus;
	printf( "Digite o numero de degraus entre 1 e 45 : " );
	scanf("%d", &degraus);

	int resultado = 0;

	for(int i=0; ;i++) {

		resultado += Permutacao((degraus-i),i, (degraus-(i*2)));

		if(((degraus-i) == i) && degraus%2 == 0) {
			break;
		} else if(((degraus-i) == i-1) && degraus%2 != 0) {
			break;
		}

	}

	printf("O resultado é: %d\n", resultado);


	return 0;
}