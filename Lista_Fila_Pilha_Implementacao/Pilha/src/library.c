#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "library.h"

NodeStackHead *createHead(void) { // return the address of a new Head that points to NULL
    
    NodeStackHead* newHead = (NodeStackHead*)malloc(sizeof(NodeStackHead));
    newHead->next = NULL;
    newHead->quantity = 0;
    return newHead;
}

NodeStack *createNode(int value) {
    NodeStack* newNode = (NodeStack*)malloc(sizeof(NodeStack));
    newNode->next = NULL;
    newNode->value = value;
    return newNode;
}

void push(NodeStackHead **head, NodeStack *newNode) {
    
    if((*head)->next == NULL) {
        (*head)->next = newNode;
        (*head)->quantity++;
    } else {
        newNode->next = (*head)-> next; // makes the newNode point to the top element of the stack
        (*head)->next = newNode; // makes the head point to the newNode, making it the first element
        (*head)->quantity++;
    }
}

NodeStack *pop(NodeStackHead **head) { //pops the top element from the stack, NOTE: Does not free the removed element
    NodeStack *poppedNode;
    if((*head)->next == NULL) {
        return NULL; // the stack is empty
    } else {
        poppedNode = ((*head)->next);
        (*head)->next = ((*head)->next)->next; // makes the head skip the element that was removed from the top, can also be NULL
        poppedNode->next = NULL;
        (*head)->quantity--;
        return poppedNode;
    }
}

void reset(NodeStackHead **head) { // clears stack
    NodeStack **lead;
    for(NodeStack* p = (*head)->next; p != NULL; p = (*lead)) {
        lead = &(p->next); // stores the address of the next element
        free(p);  // frees the current element
    }
    (*head)->next = NULL; // makes the head of the stack point to NULL
}

void listStack(NodeStackHead **head) {
    NodeStackHead *newHead = createHead(); // new head to insert the read elements
    int totalQuantity = (*head)->quantity;
    printf("There are %d elements in the stack \n", (*head)->quantity);
    for(int i=0;i<totalQuantity;i++) {
        NodeStack *poppedElement = pop(head);
        printf("- Value: %d\n", poppedElement->value);
        push(&(newHead), poppedElement); //insert the popped elements into the new head
    }
    // free((*head)); // frees the old head that isn't being used anymore
    // head = &newHead; // makes head point to the new adress where the stack was moved after the elements were read
    for(int i=0;i<totalQuantity;i++) {
        NodeStack *poppedElement = pop(&newHead);
        push(head, poppedElement); //insert the popped elements back into head in the right order
    }
    free(newHead);
}
