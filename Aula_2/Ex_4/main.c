#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int main( ) {

    int *pBuffer = malloc(sizeof(int));
    pBuffer[0] = 0;

	pBuffer = (int *)realloc_new(pBuffer, sizeof(int));
	
	pBuffer[1] = 3;

	printf("%d, %d \n", pBuffer[0], pBuffer[1]);
	return 0;
}