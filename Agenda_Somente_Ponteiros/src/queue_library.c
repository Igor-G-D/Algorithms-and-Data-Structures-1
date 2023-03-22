#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
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
    if(*front(head) == NULL) { // if queue is empty, the element added is both the first and last element
        *front(head) = newNode;
        *back(head) = newNode;
        (*(quantity(head)))++;
        return;
    } else if (strcmp(name(newNode),name(*back(head))) > 0) { // tests if the element will be added at the back of the queue
        *next(newNode) = *back(head);
        *prev(*back(head)) = newNode; 
        *back(head) = newNode;
        (*(quantity(head)))++;
        return;
    } else {
        void *p = *back(head);
        while(*next(p) != NULL && strcmp(name(newNode), name(*next(p))) < 0 ) { // iterates until it finds where the element will be added
            p = *next(p);
        }
        *prev(newNode) = p;
        *next(newNode) = *next(p);
        if(*next(p) != NULL) { // if p->next = null, it means that the element will be added in the front of the list, so it must remain NULL
            *prev(*next(p)) = newNode;
        } else {
            *front(head) = newNode; // front of the queue becomes the element added in the front
        }
        (*(quantity(head)))++;
        return;
    }

    // void * test1 = newNode;
    // void * test2 = *prev(newNode);
    // void * test3 = *next(newNode);

    // void * test4 = *front(head);
    // void * test5 = *prev(test4);
    // void * test6 = *next(test4);

    // void * test7 = *back(head);
    // void * test8 = *prev(test7);
    // void * test9 = *next(test7);
    // void * test10 = NULL;
    // if(test5) {
    //     test10 = *prev(test5);   
    // }
}

void *pop(void *head) { //pops the first element from the Queue, NOTE: Does not free the removed element
    void *poppedNode;
    void *test1 = *front(head);

	void *test2 = *next(test1);
	void *test3 = *prev(test1);
    if(*front(head) == NULL) {
        return NULL; // the Queue is empty
    } else {
        poppedNode = *front(head);
        *front(head) = *prev(*front(head)); // with the element in the front of the queue removed, the new "front" element is the one previous to that removed element
        if(*next(*back(head)) != NULL) { // it may already be null if it's the only element in the list
            *next(*front(head)) = NULL; // makes the front element stop pointing to the removed element
        } else {
            *back(head) = NULL; // if there are no elements, both front and back are NULL
        }
        *next(poppedNode) = NULL;
        *prev(poppedNode) = NULL;
        (*quantity(head))--;
        return poppedNode;
    }
}

void reset(void *head) { // clears Queue
    for(void* p = pop(head); p != NULL; p = pop(head)) { //pops every element until it finds NULL
        free(p);  // frees the current element
    }
}

void listQueue(void *head) {
    void *newHead = createHead(); // new head to insert the read elements
    printf("There are %d elements in the Queue \n", *quantity(head));
    while (*quantity(head) > 0) {
        void * test4 = *front(head);
        void * test5 = *prev(test4);
        void * test6 = *next(test4);
        void *poppedElement = pop(head);
        printf("- - Name: %s\n", name(poppedElement));
        printf("- - Age: %d\n", *age(poppedElement));
        printf("- - Phone: %s\n", tel(poppedElement));
        printf("=========================================\n");
        push(newHead, poppedElement); //insert the popped elements into the new temp head
    }
    while(*quantity(newHead) > 0) {
        void *poppedElement = pop(newHead);
        push(head, poppedElement); //insert the popped elements back into head
    }
    *next(newHead) = NULL;
    *prev(newHead) = NULL;
    free(newHead);
}



// void push(void *head, void *newNode) {
    
//     if(*((void**)(head+sizeof(int))) == NULL) { // if queue is empty, the element added is both the first and last element
//         *((void**)(head+sizeof(int))) = newNode; // head->front
//         *((void**)(head+sizeof(int)+sizeof(void*))) = newNode; //head->back;
//     } else {
//         for(void *p = *((void**)(head + sizeof(int) + sizeof(void*))); p != NULL; p = *((void**)(p+sizeof(char)*11+sizeof(int)+sizeof(char)*14+sizeof(void*)))) {
//             if(strcmp((char*)newNode, (char*)p) < 1){ //compares if the ascii value of the node to be added is smaller or equal to the value of the current node, it will be added before the current node
//                 *((void**)(newNode+sizeof(char)*11+sizeof(int)+sizeof(char)*14+sizeof(void*))) = p; // newNode->next = p
//                 *((void**)newNode+sizeof(char)*11+sizeof(int)+sizeof(char)*14) = *((void**)p+sizeof(char)*11+sizeof(int)+sizeof(char)*14); // newNode->prev = p->prev
//                 *((void**)p+sizeof(char)*11+sizeof(int)+sizeof(char)*14) = newNode; // p->previous = newNode;
//                 if(*((void**)p+sizeof(char)*11+sizeof(int)+sizeof(char)*14) == NULL) { //if the current node is at the end of the queue, the head needs to point to it as the back of the queue
//                     *((void**)(head+sizeof(int)+sizeof(void*))) = newNode; //head->back = newNode;
//                 } else {
//                     *((void**)(*((void**)newNode+sizeof(char)*11+sizeof(int)+sizeof(char)*14)) +sizeof(char)*11+sizeof(int)+sizeof(char)*14+sizeof(void*)) = newNode; //p->previous->next = newNode;
//                 }
//                 *((void**)newNode+sizeof(char)*11+sizeof(int)+sizeof(char)*14) = newNode;
//                 void *testprev = *((void**)newNode+sizeof(char)*11+sizeof(int)+sizeof(char)*14);
//                 void *testnext = *((void**)(newNode+sizeof(char)*11+sizeof(int)+sizeof(char)*14+sizeof(void*)));
//                 break;
//             }
//         }
//         if(*((void**)(newNode+sizeof(char)*11+sizeof(int)+sizeof(char)*14+sizeof(void*))) == NULL) { // newNode-> prev == NULL if it enters this condition, means that the node wasn't added anywhere else, so it will be in the front of the list
//             *((void**)newNode+sizeof(char)*11+sizeof(int)+sizeof(char)*14) = *((void**)(head+sizeof(int)));// newNode->previous = (*head)->front;
//             *((void**)((*((void**)(head+sizeof(int))))+sizeof(char)*11+sizeof(int)+sizeof(char)*14+sizeof(void*))) = newNode;//head->front->next = newNode;
//             *((void**)(head+sizeof(int))) = newNode;//(*head)->front = newNode;        
//         }
//     }
//     (*((int*)head))++; //head->quantity++
// }

// void *pop(void *head) { //pops the first element from the Queue, NOTE: Does not free the removed element
//     void *poppedNode;
//     void * test2 = *((void**)(head+sizeof(int)));
//     void * test3 = *((void**)(head+sizeof(int)+sizeof(void*)));
//     if(*((void**)(head+sizeof(int))) == NULL) { // head->front == NULL
//         return NULL; // the Queue is empty
//     } else {
//         poppedNode = *((void**)(head+sizeof(int)));//poppedNode = (*head)->front;
//         *((void**)(head+sizeof(int))) = *((void**)poppedNode+sizeof(char)*11+sizeof(int)+sizeof(char)*14);//(*head)->front = head->front->previous; // with the element in the front of the queue removed, the new "front" element is the one previous to that removed element
//         if(*((void**)((*((void**)(head + sizeof(int) + sizeof(void*))))+sizeof(char)*11+sizeof(int)+sizeof(char)*14+sizeof(void*)))) { // (*head)->back->next != NULL // it may already be null if it's the only element in the list
//                 void * test3 = *((void**)(head+sizeof(int)));
//             *((void**)((*((void**)(head+sizeof(int))))+sizeof(char)*11+sizeof(int)+sizeof(char)*14+sizeof(void*))) = NULL;//(*head)->front->next = NULL; // makes the front element stop pointing to the removed element
//         } else {
//             *((void**)(head + sizeof(int) + sizeof(void*))) = NULL;//(*head)->back = NULL; // if there are no elements, both front and back are NULL
//         }
//         *((void**)poppedNode+sizeof(char)*11+sizeof(int)+sizeof(char)*14) = NULL;//poppedNode->next = NULL;
//         *((void**)(poppedNode+sizeof(char)*11+sizeof(int)+sizeof(char)*14+sizeof(void*))) = NULL;//poppedNode->previous = NULL;
//         (*((int*)head))--;//(*head)->quantity--;
//         return poppedNode;
//     }
// }

// void reset(void *head) { // clears Queue
//     for(void* p= pop(head); p != NULL; p = pop(head)) { //pops every element until it finds NULL
//         free(p);  // frees the current element
//     }
// }

// void listQueue(void *head) {
//     void *newHead = createHead(); // new head to insert the read elements
//     printf("There are %d entries in the database \n", (*((int*)head)));
//     printf("=========================================\n");
//     while ((*((int*)head)) > 0) {
//         void *poppedElement = pop(head);
//         printf("- - Name: %s\n", (char*)(poppedElement));
//         printf("- - Age: %d\n", *((int*)(poppedElement+sizeof(char)*11)));
//         printf("- - Phone: %s\n", (char*)(poppedElement+sizeof(char)*11+sizeof(int)));
//         printf("=========================================\n");
//         push(newHead, poppedElement); //insert the popped elements into the new temp head
//     }
//     while ((*((int*)newHead)) > 0) {
//         void *poppedElement = pop(newHead);
//         push(head, poppedElement); //insert the popped elements back into head
//     }
//     free(newHead);
// }

// Functions to return specific parts of the node and head

int * quantity(void * head) {
    return ((int*)head);
}
void ** front(void * head) {
    return ((void**)(head+sizeof(int))); 
}
void ** back(void * head) {
    return ((void**)(head + sizeof(int) + sizeof(void*)));
}
void ** next(void * node) {
    return ((void**)(node+sizeof(char)*11+sizeof(int)+sizeof(char)*14+sizeof(void*)));
}
void ** prev(void * node) {
    return ((void**)node+sizeof(char)*11+sizeof(int)+sizeof(char)*14);
}
char * name(void * node) {
    return ((char*)node);
}
int * age(void * node) {
    return ((int*)(node+sizeof(char)*25));
}
char * tel(void * node) {
    return (char*)(node+sizeof(char)*11);
}
