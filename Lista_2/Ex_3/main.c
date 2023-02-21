#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int main( ) {
	int choice, toBeDeleted, searchResult;
	char name[11];
    void *pBuffer = malloc(sizeof(int));
    *((int *)pBuffer) = 0;
    
	for ( ; ; ) {
		choice = Menu( );
		switch ( choice ) {
		case 1:
			ReadInfo(&pBuffer);
			break;
		case 2:
            printf( "Inform the position to be removed: " );
            scanf("%d",&toBeDeleted);
			if (DeleteInfo(&pBuffer,toBeDeleted) == 0) {
				printf("Invalid Position\n");
			}
			break;
		case 3:
			printf( "Inform the name of the person to be searched: " );
            scanf("%s",name);
			searchResult = SearchInfo(pBuffer, name);

			if(searchResult == -1) {
				printf("Name not found\n");
			} else {
				printf("Name was found in position %d\n", searchResult); 
			}
			break;
		case 4:
			ListInfo(pBuffer);
			break;
		case 5:
			free(pBuffer);
			exit(0);
			break;
		default:
			break;
		}
	}
	return 0;
}