#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main( ) {

	int degraus;
	printf( "Digite o numero de degraus entre 1 e 45 : " );
	scanf("%d", &degraus);

	int resultado;
	int temp1 = 0;
	int temp2 = 1;

	for(int i = 0;i<degraus;i++) {
		resultado = temp1+temp2;
		temp1 = temp2;
		temp2 = resultado;
	}

	printf("O resultado é: %d\n", resultado);


	return 0;
}