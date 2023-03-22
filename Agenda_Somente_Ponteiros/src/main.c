#include <stdio.h>
#include <stdlib.h>
#include "library.h"
#include "queue_library.h"

int main( ) {
	void * test = createHead();

	push(test, createNode());

	// void *test1 = *front(test);

	// void *nodo1 = test1;
	// void *nodo1prev = *prev(nodo1);
	// void *nodo1next = *next(nodo1);

	push(test, createNode());

	// test1 = *front(test);

	// nodo1 = test1;
	// nodo1prev = *prev(nodo1);
	// nodo1next = *next(nodo1);

	// void *nodo2 = nodo1prev;
	// void *nodo2prev = *prev(nodo2);
	// void *nodo2next = *next(nodo2);

	push(test, createNode());

	//listQueue(test);
	// test1 = *front(test);

	// nodo1 = test1;
	// nodo1prev = *prev(nodo1);
	// nodo1next = *next(nodo1);

	// nodo2 = nodo1prev;
	// nodo2prev = *prev(nodo2);
	// nodo2next = *next(nodo2);

	// void *nodo3 = nodo2prev;
	// void *nodo3prev = *prev(nodo3);
	// void *nodo3next = *next(nodo3);

	push(test, createNode());

	// test1 = *front(test);

	// nodo1 = test1;
	// nodo1prev = *prev(nodo1);
	// nodo1next = *next(nodo1);

	// nodo2 = nodo1prev;
	// nodo2prev = *prev(nodo2);
	// nodo2next = *next(nodo2);

	// nodo3 = nodo2prev;
	// nodo3prev = *prev(nodo3);
	// nodo3next = *next(nodo3);

	// void *nodo4 = nodo3prev;
	// void *nodo4prev = *prev(nodo4);
	// void *nodo4next = *next(nodo4);

	//listQueue(test);

	// test1 = *front(test);

	// nodo1 = test1;
	// nodo1prev = *prev(nodo1);
	// nodo1next = *next(nodo1);

	// nodo2 = nodo1prev;
	// nodo2prev = *prev(nodo2);
	// nodo2next = *next(nodo2);

	// nodo3 = nodo2prev;
	// nodo3prev = *prev(nodo3);
	// nodo3next = *next(nodo3);

	// nodo4 = nodo3prev;
	// nodo4prev = *prev(nodo4);
	// nodo4next = *next(nodo4);

	push(test, createNode());

	// test1 = *front(test);

	// nodo1 = test1;
	// nodo1prev = *prev(nodo1);
	// nodo1next = *next(nodo1);

	// nodo2 = nodo1prev;
	// nodo2prev = *prev(nodo2);
	// nodo2next = *next(nodo2);

	// nodo3 = nodo2prev;
	// nodo3prev = *prev(nodo3);
	// nodo3next = *next(nodo3);

	// nodo4 = nodo3prev;
	// nodo4prev = *prev(nodo4);
	// nodo4next = *next(nodo4);

	// void *nodo5 = nodo4prev;
	// void *nodo5prev = *prev(nodo5);
	// void *nodo5next = *next(nodo5);

	push(test, createNode());
	
	// test1 = *front(test);

	// nodo1 = test1;
	// nodo1prev = *prev(nodo1);
	// nodo1next = *next(nodo1);

	// nodo2 = nodo1prev;
	// nodo2prev = *prev(nodo2);
	// nodo2next = *next(nodo2);

	// nodo3 = nodo2prev;
	// nodo3prev = *prev(nodo3);
	// nodo3next = *next(nodo3);

	// nodo4 = nodo3prev;
	// nodo4prev = *prev(nodo4);
	// nodo4next = *next(nodo4);

	// nodo5 = nodo4prev;
	// nodo5prev = *prev(nodo5);
	// nodo5next = *next(nodo5);

	// void *nodo6 = nodo5prev;
	// void *nodo6prev = *prev(nodo6);
	// void *nodo6next = *next(nodo6);

	listQueue(test);

	free(pop(test));

	listQueue(test);

	// void * test1 = pop(test);
	// void * test2 = pop(test);
	// void * test3 = pop(test);
	// void * test4 = pop(test);

	// char *name1 = name(test1);
	// char *name2 = name(test2);
	// char *name3 = name(test3);


	// int choice, toBeDeleted, searchResult;
	// char name[11];
    // void *pBuffer = malloc(sizeof(int));
    // *((int *)pBuffer) = 0;
    
	// for ( ; ; ) {
	// 	choice = Menu( );
	// 	switch ( choice ) {
	// 	case 1:
	// 		ReadInfo(&pBuffer);
	// 		break;
	// 	case 2:
    //         printf( "Inform the position to be removed: " );
    //         scanf("%d",&toBeDeleted);
	// 		if (DeleteInfo(&pBuffer,toBeDeleted) == 0) {
	// 			printf("Invalid Position\n");
	// 		}
	// 		break;
	// 	case 3:
	// 		printf( "Inform the name of the person to be searched: " );
    //         scanf("%s",name);
	// 		searchResult = SearchInfo(pBuffer, name);

	// 		if(searchResult == -1) {
	// 			printf("Name not found\n");
	// 		} else {
	// 			printf("Name was found in position %d\n", searchResult); 
	// 		}
	// 		break;
	// 	case 4:
	// 		ListInfo(pBuffer);
	// 		break;
	// 	case 5:
	// 		free(pBuffer);
	// 		exit(0);
	// 		break;
	// 	default:
	// 		break;
	// 	}
	// }
	// return 0;
}