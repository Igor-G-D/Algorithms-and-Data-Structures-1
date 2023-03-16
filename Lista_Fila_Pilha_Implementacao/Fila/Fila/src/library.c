#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "library.h"

NodeQueueHead *createHead(void) { // return the address of a new Head that points to NULL
    
    NodeQueueHead* newHead = (NodeQueueHead*)malloc(sizeof(NodeQueueHead));
    newHead->back = NULL;
    newHead->front = NULL;
    newHead->quantity = 0;
    return newHead;
}

NodeQueue *createNode(int value) {
    NodeQueue* newNode = (NodeQueue*)malloc(sizeof(NodeQueue));
    newNode->next = NULL;
    newNode->value = value;
    return newNode;
}

void push(NodeQueueHead **head, NodeQueue *newNode) {
    
    if((*head)->next == NULL) {
        (*head)->next = newNode;
        (*head)->quantity++;
    } else {
        newNode->next = (*head)-> next; // makes the newNode point to the top element of the Queue
        (*head)->next = newNode; // makes the head point to the newNode, making it the first element
        (*head)->quantity++;
    }
}

NodeQueue *pop(NodeQueueHead **head) { //pops the top element from the Queue, NOTE: Does not free the removed element
    NodeQueue *poppedNode;
    if((*head)->next == NULL) {
        return NULL; // the Queue is empty
    } else {
        poppedNode = ((*head)->next);
        (*head)->next = ((*head)->next)->next; // makes the head skip the element that was removed from the top, can also be NULL
        poppedNode->next = NULL;
        (*head)->quantity--;
        return poppedNode;
    }
}

void reset(NodeQueueHead **head) { // clears Queue
    NodeQueue **lead;
    for(NodeQueue* p = (*head)->next; p != NULL; p = (*lead)) {
        lead = &(p->next); // stores the address of the next element
        free(p);  // frees the current element
    }
    (*head)->next = NULL; // makes the head of the Queue point to NULL
}

void listQueue(NodeQueueHead **head) {
    NodeQueueHead *newHead = createHead(); // new head to insert the read elements
    int totalQuantity = (*head)->quantity;
    printf("There are %d elements in the Queue \n", (*head)->quantity);
    for(int i=0;i<totalQuantity;i++) {
        NodeQueue *poppedElement = pop(head);
        printf("- Value: %d\n", poppedElement->value);
        push(&(newHead), poppedElement); //insert the popped elements into the new head
    }
    // free((*head)); // frees the old head that isn't being used anymore
    // head = &newHead; // makes head point to the new adress where the Queue was moved after the elements were read
    for(int i=0;i<totalQuantity;i++) {
        NodeQueue *poppedElement = pop(&newHead);
        push(head, poppedElement); //insert the popped elements back into head in the right order
    }
    free(newHead);
}
