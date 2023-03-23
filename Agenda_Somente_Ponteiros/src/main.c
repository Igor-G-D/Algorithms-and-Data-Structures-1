#include <stdio.h>
#include <stdlib.h>
#include "library.h"
#include "queue_library.h"

int main( ) {
	void * pBuffer = malloc((sizeof(int))+(sizeof(char)*11));
	void * data = createHead();

	for ( ; ; ) {
		menu(pBuffer);
		switch ( (*choice(pBuffer)) ) {
		case 1:
			push(data, createNode());
			break;
		case 2:
            removeNode(data, pBuffer);
			break;
		case 3:
			searchInfo(data, pBuffer);
			break;
		case 4:
			list(data);
			break;
		case 5:
			clearList(data);
			printf("\nData Cleared!\n\n");
			break;
		case 6:
			clearList(data);
			free(data);
			free(pBuffer);
			exit(0);
			break;
		default:
			break;
		}
	}
	return 0;
}