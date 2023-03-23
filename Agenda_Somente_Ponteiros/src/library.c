#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
/*
====================
createHead()
    Creates a new head for a doubly linked list and returns a pointer to it.
====================
*/
void * createHead ( void ) { // return the address of a new Head that points to NULL on both ends
    
    void * newHead = malloc( sizeof( int ) + sizeof( void* ) * 2);
    * ( quantity( newHead ) ) = 0; 
    * ( front( newHead ) ) = NULL; // front of queue
    * ( back( newHead ) ) = NULL; // back of queue
    return newHead;
}

/*
====================
createNode()
    Creates a new node for a doubly linked list, getting input from the user to fill the values stores in the node, and returns a pointer to it.
====================
*/
void * createNode ( void ) {
    void * newNode = malloc ( sizeof ( char ) * 25 + sizeof ( int ) + sizeof( void * ) * 2 );

    printf( "Please inform the person's name (Max 10 characters) : " );
    scanf( "%10s", name( newNode ) ); //char name [11]
    printf( "Please inform the person's age : " );
    scanf( "%d", age( newNode ) ); // int age
    printf( "Please inform the person's phone number, (xx)xxxx-xxxx : " );
    scanf( "%13s", tel( newNode ) ); // char phone[14]

    *prev( newNode ) = NULL; // prev = NULL
    *next( newNode ) = NULL; //next = NULL
    return newNode;
 }

/*
====================
push()
    Pushes a new node into the doubly linked list, ordering by the "name" field, in ascending alphabetical order
====================
*/
void push ( void * head, void * newNode ) {
    *next( newNode ) = NULL;
    *prev( newNode ) = NULL;
    if ( ( *front ( head ) ) == NULL ) { // if queue is empty, the element added is both the first and last element
        ( *front ( head ) ) = newNode;
        ( *back ( head ) ) = newNode;
        ( *( quantity( head ) ) )++;
        return;
    } else if ( strcmp( name( newNode ),name( *back( head ) ) ) > 0 ) { // tests if the element will be added at the back of the queue
        ( *next( newNode ) ) = (*back(head));
        ( *prev( *back( head ) ) ) = newNode; 
        ( *back( head ) ) = newNode;
        ( *( quantity( head ) ) )++;
        return;
    } else {
        void * p = ( *back( head ) );
        while( *next( p ) != NULL && strcmp( name( newNode ), name( *next( p ) ) ) < 0 ) { // iterates until it finds where the element will be added
            p = ( *next( p ) );
        }

        ( *prev( newNode ) ) = p;
        ( *next( newNode ) ) = ( *next( p ) );
        if ( ( *next( p ) ) != NULL ) { // if p->next = null, it means that the element will be added in the front of the list, so it must remain NULL
            *prev( ( *next( newNode ) ) ) = newNode;
            *next( ( *prev( newNode ) ) ) = newNode;
        } else {
            ( *next( *front( head ) ) ) = newNode;
            ( *front( head ) ) = newNode; // front of the queue becomes the element added in the front
        }
        ( *( quantity( head ) ) )++;
        return;
    }
}

/*
====================
list()
    Iterates through the linked list, and prints out the quantity of elements stored, followed by the information stored in each node
====================
*/
void list ( void * head ) {
    printf( "\nThere are %d entries: \n \n", ( *quantity( head ) ) );
    if ( ( *quantity( head ) ) != 0 ) { // this is only for the menu to look pretty
        printf( "=========================================\n" );
    }
    void * p = *front( head );
    while ( p != NULL ) {
        printf( "- - Name: %s\n", name( p ) );
        printf( "- - Age: %d\n", *age( p ) );
        printf( "- - Phone: %s\n", tel( p ) );
        if( *prev( p ) != NULL ) { // this is only for the menu to look pretty
            printf( "=========================================\n" );
        }
         p = ( *prev( p ) );
    }
}

/*
====================
removeNode()
    Receives input from the user as to what name is to be searched, iterates through the linked list until it finds an element with
    a matching "name" field, and removes that element from the linked list, freeing it. NOTE: removes the first element from the back
    to the front of the doubly linked list.
====================
*/
void removeNode ( void * head, void * pBuffer ) {
    
    printf( "Please inform the person's name to be removed (Max 10 characters) : " );
    scanf( "%10s", nameSearch( pBuffer ) ); //char toBeRemoved [11]
    if ( *front(head) == NULL) { // list is empty
        return;
    }
    void *p = (*back(head));
    while (p != NULL) {
        if(strcmp((nameSearch(pBuffer)), (name(p))) == 0) {
            break;
        }
        p = ( *next( p ) );
    }
    if ( p == NULL ) {
        return;
    }
    if ( ( *prev( p ) ) != NULL ) {
        ( *next( *prev( p ) ) ) = ( *next( p ) ); // makes the element before the current point to the element after the current
    } else {
        ( *back( head ) ) = ( *next( p ) ); // if its null, means the element removed was the one in the back of the queue
    }
    if ( ( *next( p ) ) != NULL ) {
        ( *prev( *next( p ) ) ) = ( *prev( p ) ); // makes the element after the curent point to the element before the current
    } else {
        ( *front( head ) ) = ( *prev( p ) ); // if its null, means the element removed was the one in the front of the queue
    }
    free( p );
    ( *( quantity( head ) ) )--;
}

/*
====================
searchInfo()
    Receives input from the user on what name to be searched, and lists the info of all nodes that have a matching "name" field
====================
*/
void searchInfo ( void * head, void * pBuffer ) {
    printf ( "Please inform the name to be searched (Max 10 characters) : " );
    scanf ( "%s", nameSearch( pBuffer ) ); //char toBeRemoved [11]
    void * p = *back( head );
    if ( p == NULL ) {
        printf( "=========================================\n" );
        printf( "\nName not in the database\n\n" );
    } else {
        while ( p != NULL ) {
            if ( strcmp( ( nameSearch( pBuffer ) ), ( name( p ) ) ) == 0 ) {
                printf( "=========================================\n" );
                printf( "- - Name: %s\n", name( p ) );
                printf( "- - Age: %d\n", *age( p ) );
                printf( "- - Phone: %s\n", tel( p ) );                
            }
            p = ( *next( p ) );
        }
    }
}

/*
====================
clearList()
    Iterates through the linked list, freeing each element, and setting the references that the head has to the front and back of 
    the list to NULL, also setting the quantity of elements stored to 0, since the list will now be empty
====================
*/
void clearList ( void * head ) {
    void * p = *back( head );
    while ( p != NULL)  {
        void * toRemove = p;
        p = *next( p );
        free( toRemove );
    }
    *back( head ) = NULL;
    *front( head ) = NULL;
    *( quantity( head ) ) = 0;
}

/*
====================
menu()
    Receives input from the user on what menu option described is chosen, writing that choice into pBuffer to be used in the switch inside the main() function
====================
*/

void menu( void *pBuffer ) {
	do {
        printf( "=========================================\n" );
		printf( "-- Menu:\n");
		printf( "\t 1. Insert one person's information\n" );
		printf( "\t 2. Delete by name\n" );
		printf( "\t 3. Search by name\n" );
		printf( "\t 4. List all\n" );
		printf( "\t 5. Clear data\n" );
        printf( "\t 6. Exit\n" );
		printf( "-- Enter your choice: " );
		scanf( "%d", choice( pBuffer ) );
        printf( "=========================================\n" );
	} while ( ( *choice( pBuffer ) ) <= 0 || ( *choice( pBuffer ) ) > 6 );
	getchar( );
}

// Functions to return specific parts of the node, pBuffer and head

/*
====================
quantity()
    Receives a pointer to the head, and returns a pointer to the integer that stores the quantity of elements inside the doubly linked list
====================
*/
int * quantity ( void * head ) {
    return ( ( int* )( head ) );
}

/*
====================
front()
    Receives a pointer to the head, and returns a pointer to the front element of the doubly linked list
====================
*/
void ** front ( void * head) {
    return ( ( void** )( ( head ) + ( sizeof( int ) ) ) ); 
}

/*
====================
back()
    Receives a pointer to the head, and returns a pointer to the back element of the doubly linked list
====================
*/
void ** back ( void * head ) {
    return ( (void**)( ( head ) + ( sizeof( int ) ) + ( sizeof( void* ) ) ) );
}

/*
====================
next()
    Receives a pointer to a node, and returns a pointer to the "next" element said node is pointing to
====================
*/
void ** next ( void * node ) {
    return ( ( void** )( ( node ) + ( sizeof( char ) * 25 ) + ( sizeof( int ) ) + ( sizeof ( void* ) ) ) );
}

/*
====================
prev()
    Receives a pointer to a node, and returns a pointer to the "prev" element said node is pointing to
====================
*/
void ** prev ( void * node ) {
    return ( ( void** )( ( node ) + ( sizeof( char ) * 25 ) + ( sizeof( int ) ) ) );
}

/*
====================
name()
    Receives a pointer to a node, and returns a pointer to the "name" field of that node
====================
*/
char * name ( void * node ) {
    return ( ( char* )( node ) );
}

/*
====================
age()
    Receives a pointer to a node, and returns a pointer to the "age" field of that node
====================
*/
int * age ( void * node ) {
    return ( ( int* )( ( node ) + ( sizeof( char ) * 25 ) ) );
}

/*
====================
tel()
    Receives a pointer to a node, and returns a pointer to the "tel"(phone) field of that node
====================
*/
char * tel ( void * node ) {
    return ( ( char* )( ( node ) + ( sizeof( char ) * 11) ) );
}

/*
====================
choice()
    Receives a pointer to pBuffer, and returns a pointer to the "choice" integer, used to determine the choice of the user for the menu option
====================
*/
int * choice ( void * pBuffer ) {
    return ( ( int* )( pBuffer ) );
}

/*
====================
nameSearch()
    Receives a pointer to pBuffer, and returns a pointer to the "nameSearch" string, used in a few functions to read a name informed by the user
====================
*/
char * nameSearch ( void * pBuffer ) {
    return ( ( char* )( ( pBuffer ) + ( sizeof( int ) ) ) );
}