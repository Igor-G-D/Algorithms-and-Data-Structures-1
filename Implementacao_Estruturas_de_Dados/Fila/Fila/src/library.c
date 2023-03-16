#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "library.h"

NodeQueueHead *createHead(void) { // return the address of a new Head that points to NULL on both ends
    
    NodeQueueHead* newHead = (NodeQueueHead*)malloc(sizeof(NodeQueueHead));
    newHead->back = NULL;
    newHead->front = NULL;
    newHead->quantity = 0;
    return newHead;
}

NodeQueue *createNode(int value) {
    NodeQueue* newNode = (NodeQueue*)malloc(sizeof(NodeQueue));
    newNode->next = NULL;
    newNode->previous = NULL;
    newNode->value = value;
    return newNode;
}

void push(NodeQueueHead **head, NodeQueue *newNode) {
    
    if((*head)->front == NULL) { // if queue is empty, the element added is both the first and last element
        (*head)->front = newNode;
        (*head)->back = newNode;
        (*head)->quantity++;
    } else {
        newNode->next = (*head)-> back; // makes the newNode point to the last element of the Queue
        ((*head)->back)->previous = newNode; //makes the node at the end of the list point back to the element added at the back of the queue (doubly linked list)
        (*head)->back = newNode; // makes the head point to the newNode, making it the last element in the Queue
        (*head)->quantity++;
    }
}

NodeQueue *pop(NodeQueueHead **head) { //pops the first element from the Queue, NOTE: Does not free the removed element
    NodeQueue *poppedNode;
    if((*head)->front == NULL) {
        return NULL; // the Queue is empty
    } else {
        poppedNode = (*head)->front;
        (*head)->front = poppedNode->previous; // with the element in the front of the queue removed, the new "front" element is the one previous to that removed element
        if((*head)->back->next != NULL) { // it may already be null if it's the only element in the list
            (*head)->front->next = NULL; // makes the front element stop pointing to the removed element
        } else {
            (*head)->back = NULL; // if there are no elements, both front and back are NULL
        }
        poppedNode->next = NULL;
        poppedNode->previous = NULL;
        (*head)->quantity--;
        return poppedNode;
    }
}

void reset(NodeQueueHead **head) { // clears Queue
    for(NodeQueue* p= pop(head); p != NULL; p = pop(head)) { //pops every element until it finds NULL
        free(p);  // frees the current element
    }
}

void listQueue(NodeQueueHead **head) {
    int totalQuantity = (*head)->quantity;
    printf("There are %d elements in the Queue \n", (*head)->quantity);
    for(int i=0;i<totalQuantity;i++) {
        NodeQueue *poppedElement = pop(head);
        printf("- Value: %d\n", poppedElement->value);
        push(head, poppedElement); //insert the popped elements into the new queue
    }
}
