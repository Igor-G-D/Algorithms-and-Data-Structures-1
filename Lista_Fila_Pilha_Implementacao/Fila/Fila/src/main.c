#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "library.h"

int main ( ) {
	NodeStackHead *head = createHead();

	push(&(head), createNode(67));
	push(&(head), createNode(56));
	push(&(head), createNode(45));
	push(&(head), createNode(34));
	push(&(head), createNode(23));
	push(&(head), createNode(12));
	listStack(&(head));
	printf("--------------\n");
	free(pop(&(head)));
	free(pop(&(head)));
	free(pop(&(head)));
	free(pop(&(head)));
	listStack(&(head));
	printf("--------------\n");
	push(&(head), createNode(123));
	push(&(head), createNode(246));
	listStack(&(head));
	free(pop(&(head)));
	free(pop(&(head)));
	free(pop(&(head)));
	free(pop(&(head)));
	printf("--------------\n");
	listStack(&(head));

	free(head);

	return 0;
}