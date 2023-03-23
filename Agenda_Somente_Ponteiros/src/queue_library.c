#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_library.h"

void *createHead(void) { // return the address of a new Head that points to NULL on both ends
    
    void* newHead = malloc(sizeof(int)+sizeof(void*)*2);
    *((int*)newHead) = 0; 
    *((void**)(newHead+sizeof(int))) = NULL; // front of queue
    *((void**)(newHead + sizeof(int) + sizeof(void*))) = NULL; // back of queue
    return newHead;
}


void *createNode(void) {
    void *newNode = malloc(sizeof(char)*25 + sizeof(int)+ sizeof(void *)*2);

    printf( "Please inform the person's name (Max 10 characters) : " );
    scanf( "%s", name(newNode) ); //char name [11]
    printf( "Please inform the person's age : " );
    scanf( "%d", age(newNode) ); // int age
    printf( "Please inform the person's phone number, (xx)xxxx-xxxx : " );
    scanf( "%s", tel(newNode)); // char phone[14]

    *prev(newNode) = NULL; // prev = NULL
    *next(newNode) = NULL; //next = NULL
    return newNode;
 }

void push(void *head, void *newNode) {
    *next(newNode) = NULL;
    *prev(newNode) = NULL;
    if((*front(head)) == NULL) { // if queue is empty, the element added is both the first and last element
        (*front(head)) = newNode;
        (*back(head)) = newNode;
        (*(quantity(head)))++;
        return;
    } else if (strcmp(name(newNode),name(*back(head))) > 0) { // tests if the element will be added at the back of the queue
        (*next(newNode)) = (*back(head));
        (*prev(*back(head))) = newNode; 
        (*back(head)) = newNode;
        (*(quantity(head)))++;
        return;
    } else {
        void *p = (*back(head));
        while(*next(p) != NULL && strcmp(name(newNode), name(*next(p))) < 0 ) { // iterates until it finds where the element will be added
            p = (*next(p));
        }

        (*prev(newNode)) = p;
        (*next(newNode)) = (*next(p));
        if((*next(p)) != NULL) { // if p->next = null, it means that the element will be added in the front of the list, so it must remain NULL
            *prev((*next(newNode))) = newNode;
            *next((*prev(newNode))) = newNode;
        } else {
            (*next(*front(head))) = newNode;
            (*front(head)) = newNode; // front of the queue becomes the element added in the front
        }
        (*(quantity(head)))++;
        return;
    }
}

void list(void *head) {
    printf("\nThere are %d entries: \n \n", (*quantity(head)));
    printf("=========================================\n");
    void *p = *front(head);
    while (p != NULL) {
        printf("- - Name: %s\n", name(p));
        printf("- - Age: %d\n", *age(p));
        printf("- - Phone: %s\n", tel(p));
        if(*prev(p) != NULL) { // this is only for the menu to look pretty
            printf("=========================================\n");
        }
         p = (*prev(p));
    }
}

void removeNode(void *head, void * pBuffer) {
    
    printf( "Please inform the person's name to be removed (Max 10 characters) : " );
    scanf( "%s", nameSearch(pBuffer)); //char toBeRemoved [11]
    if(*front(head) == NULL) { // list is empty
        return;
    }
    void *p = (*back(head));
    while (p != NULL) {
        if(strcmp((nameSearch(pBuffer)), (name(p))) == 0) {
            break;
        }
        p = (*next(p));
    }
    if(p == NULL) {
        return;
    }
    if((*prev(p)) != NULL) {
        (*next(*prev(p))) = (*next(p)); // makes the element before the current point to the element after the current
    } else {
        (*back(head)) = (*next(p)); // if its null, means the element removed was the one in the back of the queue
    }
    if((*next(p)) != NULL) {
        (*prev(*next(p))) = (*prev(p)); // makes the element after the curent point to the element before the current
    } else {
        (*front(head)) = (*prev(p)); // if its null, means the element removed was the one in the front of the queue
    }
    free(p);
    (*(quantity(head)))--;
}

void searchInfo(void *head, void * pBuffer) {
    printf( "Please inform the person's name to be searched (Max 10 characters) : " );
    scanf( "%s", nameSearch(pBuffer)); //char toBeRemoved [11]
    void *p = *back(head);

    while (p != NULL) {
        if(strcmp((nameSearch(pBuffer)), (name(p))) == 0) {
            break;
        }
        p = (*next(p));
    }
    if(p == NULL) {
        printf("=========================================\n");
        printf("Name not in the database\n");
    } else {
        printf("=========================================\n");
        printf("- - Name: %s\n", name(p));
        printf("- - Age: %d\n", *age(p));
        printf("- - Phone: %s\n", tel(p));
    }
}

void clearList(void *head) {
    void* p = *back(head);
    while (p != NULL) {
        void *toRemove = p;
        p = *next(p);
        free(toRemove);
    }
    *back(head) = NULL;
    *front(head) = NULL;
    *(quantity(head)) = 0;
}

void menu( void *pBuffer ) {
	do {
        printf("=========================================\n");
		printf( "-- Menu:\n");
		printf( "\t 1. Insert one person's information\n" );
		printf( "\t 2. Delete by name\n" );
		printf( "\t 3. Search by name\n" );
		printf( "\t 4. List all\n" );
		printf( "\t 5. Clear data\n" );
        printf( "\t 6. Exit\n" );
		printf( "-- Enter your choice: " );
		scanf( "%d", choice(pBuffer));
        printf("=========================================\n");
	} while ( (*choice(pBuffer)) <= 0 || (*choice(pBuffer)) > 6 );
	getchar( );
}

// Functions to return specific parts of the node, pBuffer and head

int * quantity(void * head) {
    return ((int*)(head));
}
void ** front(void * head) {
    return ((void**)((head)+(sizeof(int)))); 
}
void ** back(void * head) {
    return ((void**)((head) + (sizeof(int)) + (sizeof(void*))));
}
void ** next(void * node) {
    return ((void**)((node)+(sizeof(char)*11)+(sizeof(int))+(sizeof(char))*(14+sizeof(void*))));
}
void ** prev(void * node) {
    return ((void**)((node)+(sizeof(char)*11)+(sizeof(int))+(sizeof(char)*14)));
}
char * name(void * node) {
    return ((char*)(node));
}
int * age(void * node) {
    return ((int*)((node)+(sizeof(char)*25)));
}
char * tel(void * node) {
    return ((char*)((node)+(sizeof(char)*11)));
}
int * choice(void * pBuffer) {
    return ((int*)(pBuffer));
}
char * nameSearch(void * pBuffer) {
    return ((char*)((pBuffer) + (sizeof(int))));
}