#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

// format pBuffer: (int currentSize, int choice, int posToDelete);
// currentSize = (int *)pBuffer;
// choice = (int *)(pBuffer + sizeof(int))
// int posToDelete = (char*)(pBuffer + sizeof(int)*2);

// format void *nodeHead: 
//                  void *start
//                  void *end

// format void *node:
//                  char name[11];
//                  int  age;
//                  char phone[14];
//                  void * previous;
//                  void * next;
/*
====================
ReadInfo
 Reads info of the user and adds it to the end of void **pBuffer
====================
*/

void ReadInfo ( void **pBuffer, void **dataHead ) {

    void *newNode = malloc(sizeof(char)*11 + sizeof(int) + sizeof(char)*14 + (sizeof(void *))*2);
    *(newNode + sizeof(char)*11 + sizeof(int) + sizeof(char)*14) = NULL; // void * prev = NULL
    *(newNode + sizeof(char)*11 + sizeof(int) + sizeof(char)*14 + sizeof(void *)) = NULL; // void * next = NULL;

    printf( "Please inform the person's name (Max 10 characters) : " );
    scanf( "%s", newNode ); //char name [11]
    printf( "Please inform the person's age : " );
    scanf( "%d", (newNode+sizeof(char)*11) ); // int age
    printf( "Please inform the person's phone number, (xx)xxxx-xxxx : " );
    scanf( "%s", (newNode+sizeof(char)*11+sizeof(int)) ); // char phone[14]
     
    // reads input from the user

    void *pData = ((*dataHead) + sizeof(void*)); // points to the end of the queue  

    for (pData; *pData ) { // adds each char to void pointer 1 by 1
        *( char * )pBufferEnd = name[ i ];
        pBufferEnd += sizeof( char );
    }

    *( ( int * )pBufferEnd ) = idade; // adds age to void pointer
    pBufferEnd += sizeof( int );

    for ( int i=0;i<14;i++ ) { // adds each char to void pointer 1 by 1
        *( char * )pBufferEnd = phone[ i ];
        pBufferEnd += sizeof( char );
    }

    (*((int *)*pBuffer))++; // adds +1 to the number of people stored in the beggining of the void pointer
}

/*
====================
ListInfo
 Prints out info stored in *pBuffer
====================
*/

void ListInfo ( void *pBuffer ) {

    int numberStored = *( ( int * ) pBuffer );

    pBuffer = pBuffer + ( sizeof ( int ) );

    for( int i=0 ; i < numberStored ; i++ ) { //Iterates over each person's stored info and prints it out
        printf( "Position %d: \n", i);
        printf( "    Name: %s\n", ( char * )pBuffer);
        pBuffer += 11 * sizeof( char );
        printf( "    Age: %d\n", *( int * )pBuffer);
        pBuffer += sizeof( int );
        printf( "    Phone: %s\n", ( char * )pBuffer);
        pBuffer += 14 * sizeof( char );
    }
}

/*
====================
SearchInfo
 Searches for the first instance of "nameSearch" inside pBuffer, returns -1 if not found, if found,
 returns the position of where the name was found
====================
*/

int SearchInfo( void *pBuffer, char nameSearch[ 11 ] ) {

    int numberStored = *( ( int * )pBuffer);

    pBuffer = pBuffer + ( sizeof( int ) );

    for( int i=0 ; i < numberStored ; i++ ) { //Iterates over each person's stored info and compares the name to the search term
        if ( ( strcmp( nameSearch,( ( char * )pBuffer ) ) ) == 0 ) {
            return i;
        }
        pBuffer += 11*sizeof( char ) + sizeof( int ) + 14*sizeof( char );
    }
    return -1;
}

/*
====================
DeleteInfo
 Deletes the positionToDelete position from the void * pointer, and frees the uneccessary memory, returns 0 if the position to be deleted is invalid, return 1 if valid
====================
*/

int DeleteInfo( void **pBuffer, int positionToDelete ) {

    void *pBufferTemp = ( *pBuffer ) + ( sizeof( int ) );
    int numberStored = *( ( int * ) ( *pBuffer ) );
    int memBlockSize = 11 * sizeof( char ) + sizeof( int ) + 14 * sizeof( char ); // size of the total memory occupied by the info of each person
    int found = 0;
    if( positionToDelete < 0 || positionToDelete > numberStored-1 ) { //return 0 if invalid position
        return 0;
    }
    if( positionToDelete != numberStored ) { //if the position to delete is the last one, just needs to realloc to free the end of the memory the pointer is pointing to
        for( int i=0 ; i<( numberStored-1 ) ; i++ ) { //Iterates over each person's stored info, if found, it reads the memory of the next block of info to skip over the info to be deleted
            if ( i == positionToDelete ) {
                found = 1; 
            }
            for ( int j=0 ; j<11 ; j++ ) { // 
                *( char * )pBufferTemp = *( char* )( pBufferTemp + ( memBlockSize * found ) );
                pBufferTemp += sizeof(char);
            }

            *( ( int * )pBufferTemp ) = *( int * )( pBufferTemp + memBlockSize*found ); 
            pBufferTemp += sizeof(int);

            for( int j=0 ; j<14 ; j++) { 
                *( char * )pBufferTemp = *( char* )( pBufferTemp + ( memBlockSize * found ) );
                pBufferTemp += sizeof( char );
            }
        }
    }
    ( *pBuffer ) = realloc( ( *pBuffer ), ( sizeof( int ) ) + ( numberStored - 1 ) * memBlockSize ); // frees the last block of info after moving all the memory to remain stored
    ( *( ( int * )( *pBuffer ) ) )--; // -1 to the counter of how many people's info are stored
    return 1;
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