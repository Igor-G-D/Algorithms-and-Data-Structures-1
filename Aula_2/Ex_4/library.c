#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

/*
====================
ReadInfo
 Reads info of the user and adds it to the end of void **pBuffer
====================
*/

void *realloc_new(void *pont,size_t newSize) {
    int originalSize = sizeof(pont);
    void *newPointer = malloc(originalSize+newSize);

    memcpy(newPointer, pont, originalSize);

    free(pont);
    return newPointer;
}

/*
====================
Menu
 Displays the menu and returns the chosen option as an integer
====================
*/

int Menu( void ) {

	int c = 0;
	do {
		printf( "-- Menu:\n");
		printf( "\t 1. Insert one person's information\n" );
		printf( "\t 2. Delete by position\n" );
		printf( "\t 3. Search by name\n" );
		printf( "\t 4. List all\n" );
        printf( "\t 5. Exit\n" );
		printf( "-- Inform your choice: " );
		scanf( "%d", &c );
	} while ( c <= 0 || c > 5 );
	getchar( );
	return c;
}