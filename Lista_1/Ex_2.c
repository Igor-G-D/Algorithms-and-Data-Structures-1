#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

void Insere( char **baseString,char * newString );
void Apaga ( char **baseString, char *toBeDeletedString );
void Imprime( char * s ) ;
int Menu( void );
void LerString( char palavra[ MAX ] );

int main( ) {
	int escolha;
    char *list = NULL;
    char *name = ( char* )malloc( sizeof( char ) * 256);
    
	for ( ; ; ) {
		escolha = Menu( );
		switch ( escolha ) {
		case 1:
            printf( "Digite o nome a ser inserido: " );
            LerString( name );
			Insere( &list, name );
			break;
		case 2:
            printf( "Digite o nome a ser removido: " );
            LerString( name );
			Apaga( &list, name );
			break;
		case 3:
			Imprime( list );
			break;
		case 4:
			free( name );
			free( list );
			exit( 0 );
			break;
		default:
			break;
		}
	}
	return 0;
}

/*
====================
Menu

Displays the menu, and returns the chosen number from the user
====================
*/

int Menu( void )
{
	int c = 0;
	do {
		printf("-- Menu:\n");
		printf("\t 1. Inserir um nome\n");
		printf("\t 2. Excluir um nome\n");
		printf("\t 3. Listar nomes\n");
		printf("\t 4. Sair\n");
		printf("-- Digite sua escolha: ");
		scanf("%d", &c);
	} while ( c <= 0 || c > 4 );
	getchar( );
	return c;
}

/*
====================
LerString

Reads a string of a maximum of 256 characters
====================
*/

void LerString( char palavra[ MAX ] ) {
	int i = 0;
	char c;

	c = getchar( );
	while ( ( c != '\n' ) && ( i < MAX ) ) {
		palavra[ i++ ] = c;
		c = getchar( );
	}
    palavra[ i ] = '\0';


}

/*
====================
Insere
 Recieves a pointer to the address of a String that determines the base String, as well as a String that is to be added. If the base string is empty,
 it allocates new memory and inserts the newString value into the base String, if the baseString already has content, it reallocs memory and inserts the
 new String separated by a comma into the BaseString.
====================
*/

void Insere( char **baseString,char * newString )
{
    int sizeBase;
	if ( *baseString == NULL ) {
        sizeBase = 0;
    } else {
        sizeBase = strlen(*baseString);
    }
    int sizeNew = strlen( newString );

	if( sizeBase == 0 ) {
        *baseString = ( char* )malloc( sizeof( char ) * sizeNew + 1);
        strcpy( *baseString, newString );
    } else {
        int counter = 0;

        ( *baseString ) = ( char* )realloc( ( *baseString ), ( ( sizeBase+sizeNew + 2 ) * sizeof( char ) ) );
        ( *baseString )[ sizeBase ] = ',';

        for( int i = sizeBase+1 ; i < ( sizeBase + sizeNew + 2 ) ; i++ ) {
            ( *baseString )[ i ] = newString[ counter ];
            counter++;
		}	
    }
}

/*
====================
Apaga
 Finds the first occurence of char *needle in char *haystack where each element is separated by ",", and alters the baseString (haystack) that was passed as a parameter
 to exclude the needle.
====================
*/

void Apaga ( char **baseString, char *toBeDeletedString )
{
	int found = 0;
    char *tempBase = ( char* )malloc( ( strlen( *baseString )+1 ) * sizeof( char ) );
    strcpy( tempBase, *baseString );
    free( *baseString );
	*baseString = NULL;
    char *temp = strtok( tempBase,"," );
    while ( temp != NULL ) {
        if( strcmp( temp, toBeDeletedString ) != 0 || found ) {
            Insere( baseString, temp );
        } else {
			found = 1;
		}
		temp = strtok( NULL,"," );
    }
	free( temp );
	free( tempBase );

}

/*
====================
Imprime
 prints out the list of stored words
====================
*/

void Imprime( char * s )
{
	printf("Name List: %s\n", s);
}
