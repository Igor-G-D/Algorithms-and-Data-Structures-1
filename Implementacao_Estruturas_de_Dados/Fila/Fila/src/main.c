#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "library.h"

int main ( ) {
	NodeQueueHead *head = createHead();

	push(&(head), createNode(67));
	push(&(head), createNode(56));
	push(&(head), createNode(45));
	push(&(head), createNode(34));
	push(&(head), createNode(23));
	push(&(head), createNode(12));
	listQueue(&(head));
	printf("--------------\n");
	free(pop(&(head)));
	free(pop(&(head)));
	free(pop(&(head)));
	free(pop(&(head)));
	listQueue(&(head));
	printf("--------------\n");
	push(&(head), createNode(123));
	push(&(head), createNode(246));
	listQueue(&(head));
	free(pop(&(head)));
	free(pop(&(head)));
	free(pop(&(head)));
	free(pop(&(head)));
	printf("--------------\n");
	listQueue(&(head));

	push(&(head), createNode(67));
	push(&(head), createNode(56));
	push(&(head), createNode(45));
	push(&(head), createNode(34));
	push(&(head), createNode(23));
	push(&(head), createNode(12));

	reset(&(head));

	free(head);
	
	return 0;
}