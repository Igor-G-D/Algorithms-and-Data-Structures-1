#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int IsValid(char * s);

/*
====================
Main

Reads from input.txt file, separates each line into an appropriately sized string, and runs it through the IsValid function, printing into the console the result
====================
*/

int main( ) {

    FILE *file;
    char *string;
    int breakVar,breakVar2 = 0;

    if ( ( file = fopen( "/home/igor/Programming/Algoritmos_E_Estrutura_De_Dados_1/Aula_1/input.txt", "r" ) ) == NULL ) {
		printf( "Error on opening file!\n" );
		exit( 1 );
	}
	while ( !feof( file ) ) {
        int counter = 0;
        char *word = ( char* )malloc( sizeof( char ) );
        while ( !feof( file ) ) {
            char currentChar = fgetc( file );
            if( currentChar == '\n' || currentChar == '\377' ) {
                break;
            }
            else {
                word [ counter ] = currentChar;
                counter++;
                word = ( char* )realloc( word, ( 1 + counter ) * sizeof( char ) );
            }
        }
        word [ counter ] = '\0';
        int result = IsValid( word );
        if( result ) {
            printf ( "%s e valido\n", word ) ;
        } else {
            printf ( "%s nao e valido\n", word ) ;
        }
        free( word );
    }

    fclose( file );

    return 0;
}

/*
====================
IsValid

Receives a variable length string, and returns if the contents, only being composed of "(","[","{",")","]","}" is a valid expression
====================
*/

int IsValid( char * s ) {

    int strLength = strlen( s );
    if ( strLength % 2 != 0 ) {
        return 0;
    }
    char *pile;
    pile = ( char * ) malloc( ( strLength / 2 )*sizeof ( char ) );
    int topPile = -1;
    for( int i=0;i<strLength;i++ ) {

       if( s[ i ] == '(' || s[ i ] == '[' || s[ i ] == '{' ) {
           topPile++;
           if( topPile == strLength/2 ){
                free ( pile );
               return 0;
           } else {
                pile[ topPile ] = s[ i ];
           } 
        } else if ( topPile == -1 ) {
            free ( pile );
            return 0;
        } else if ( s[ i ] == ')' ) {
            if ( pile[ topPile ] != '(' ) {
                free ( pile );
                return 0;
            }
            topPile--;
        } else if ( s[ i ] == ']' ) {
            if ( pile [ topPile ] != '[' ) {
                free ( pile );
                return 0;
            }
            topPile--;
        } else if (s[ i ] == '}') {
            if( pile [ topPile ] != '{' ) {
                free ( pile );
                return 0;
            }
            topPile--;
        }
    }
    if ( topPile != -1 ) {
        free ( pile );
        return 0;
    } else {
        free ( pile );
        return 1;
    }

}

