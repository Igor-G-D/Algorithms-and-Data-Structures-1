#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct _NodeStack{
    int value;
    struct _NodeStack *next;
} NodeStack;

typedef struct {
    int quantity;
    NodeStack *next;
} NodeStackHead;

int isPalindrome( struct ListNode* head );
NodeStackHead *createHead( void );
NodeStack *createNode( int value );
void push( NodeStackHead **head, NodeStack *newNode );
NodeStack *pop( NodeStackHead **head );
void reset( NodeStackHead **head );
void listStack( NodeStackHead **head );

struct ListNode* newList( int * numbers, int size ); // New function
void freeList( struct ListNode *head ); //New function

int main( int argc, char const *argv[ ] )
{
    
    int test1[ 8 ] = { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 };
    int test2[ 1 ] = { 1 };
    int test3[ 9 ] = { 1 , 2 , 3 , 4 , 5 , 4 , 3 , 2 , 1 };
    int test4[ 6 ] = { 1 , 2 , 3 , 3 , 2 , 1 };
    int test5[ 5 ] = { 1 , 2 , 3 , 4 , 1 };
    int test6[ 2 ] = { 1 , 1 };
    struct ListNode *head1 = newList( test1, 8 );
    struct ListNode *head2 = newList( test2, 1 );
    struct ListNode *head3 = newList( test3, 9 );
    struct ListNode *head4 = newList( test4, 6 );
    struct ListNode *head5 = newList( test5, 5 );
    struct ListNode *head6 = newList( test6, 2 );

    printf( "[1,2,3,4,5,6,7,8] expected 0, result: %d\n", isPalindrome( head1 ) );

    printf( "[1] expected 1, result: %d\n", isPalindrome( head2 ) );

    printf( "[1,2,3,4,5,4,3,2,1] expected 1, result: %d\n", isPalindrome( head3 ) );

    printf( "[1,2,3,3,2,1] expected 1, result: %d\n", isPalindrome( head4 ) );

    printf( "[1,2,3,4,1] expected 0, result: %d\n", isPalindrome( head5 ) );
    
    printf( "[1,1] expected 1, result: %d\n", isPalindrome( head6 ) );

    freeList( head1 ); //frees all the linked lists used for testing
    freeList( head2 );
    freeList( head3 );
    freeList( head4 );
    freeList( head5 );
    freeList( head6 );

    return 0;
}

/*
====================
isPalindrome()
 
    Tests a linked list to see if the elements contained inside each element constitute a palindrome.
====================
*/

int isPalindrome ( struct ListNode *head ) { 
    struct ListNode *fast = head->next; // pointer that goes through linked list 2 positions at a time
    struct ListNode *middle = head; // pointer that geos through linked lise 1 position at a time
    NodeStackHead *stack = createHead( );
    int isOdd = 0;
    if ( fast == NULL ) {
        reset( &( stack ) );
        free( stack ); // NEW: added free(stack)
        return 1; // if there is only one element, means that it's a palindrome
    }
    while ( fast->next != NULL ) { 
        if ( fast->next->next == NULL ) {
            isOdd = 1;
            break;
        }
        fast = fast->next->next;
        push( &( stack ), createNode( middle->val ) );
        middle = middle->next;

    }
    push( &( stack ), createNode( middle->val ) );
    middle = middle->next;
    if ( isOdd ) {
        middle = middle->next; // if its odd, the middle needs to advance one more to skip over the middle character
    }
    
    // now with the stack containing all the elements that are in the first half, needs to test to see if it's a palindrome

    for ( ; middle != NULL ; middle = middle->next ) { //compares elements being iterated through in the linked list to the top of the stack
        NodeStack *temp = pop( &( stack ) );
        if ( temp->value != middle->val ) {
            reset( &( stack ) );
            free( temp );
            free( stack ); //NEW:  added free(stack);
            return 0;
        }
        free( temp );
    }
    reset( &stack ); 
    free( stack ); //NEW: added free(stack);
    
    return 1;
} 

/*
====================
newList()
    Recieves an array of ints, as well as the size of the array, and returns a pointer to a linked list with all those values in the same order
====================
*/

struct ListNode* newList ( int * numbers, int size ) {
    struct ListNode *head = ( struct ListNode * )malloc( sizeof( struct ListNode ) );
    head->val = numbers[ 0 ];
    head->next = NULL;
    struct ListNode *current = head;
    for ( int i=1 ; i<size ; i++ ) {
        struct ListNode *new = ( struct ListNode * )malloc( sizeof( struct ListNode ) );
        new->next = NULL;
        new->val = numbers[ i ];
        current->next = new;
        current = current->next;
    }
    return head;
}

/*
====================
freeList()
    Recieves the pointer to a list, and frees the head as well as all of the nodes that follow
====================
*/

void freeList ( struct ListNode *head ) {
    struct ListNode* current = head;
    struct ListNode* next;
    while ( current != NULL ) {
        next = current->next;
        free( current );
        current = next;
    }
}

/*
====================
createHead()
    Creates the head of a stack, with the quantity of elements in the stack being also stored in the head
====================
*/

NodeStackHead *createHead ( void ) { // return the address of a new Head that points to NULL
    
    NodeStackHead* newHead = ( NodeStackHead* )malloc( sizeof( NodeStackHead ) );
    newHead->next = NULL;
    newHead->quantity = 0;
    return newHead;
}

/*
====================
createNode()
    Creates a new node to be added to the stack with the value passed as a parameter stored in it.
====================
*/

NodeStack *createNode ( int value ) {
    NodeStack* newNode = ( NodeStack* )malloc( sizeof( NodeStack ) );
    newNode->next = NULL;
    newNode->value = value;
    return newNode;
}

/*
====================
push()
    pushes the element passed as a parameter to the head of the stack that is also passed as a parameter
====================
*/

void push ( NodeStackHead **head, NodeStack *newNode ) {
    
    if ( ( *head )->next == NULL ) {
        ( *head )->next = newNode;
        ( *head )->quantity++;
    } else {
        newNode->next = ( *head )-> next; // makes the newNode point to the top element of the stack
        ( *head )->next = newNode; // makes the head point to the newNode, making it the first element
        ( *head )->quantity++;
    }
}

/*
====================
pop()
    pops the top element of the stack from it, and returns that element
====================
*/

NodeStack *pop ( NodeStackHead **head ) { //pops the top element from the stack, NOTE: Does not free the removed element
    NodeStack *poppedNode;
    if ( ( *head )->next == NULL) {
        return NULL; // the stack is empty
    } else {
        poppedNode = ( ( *head )->next);
        ( *head )->next = ( ( *head )->next )->next; // makes the head skip the element that was removed from the top, can also be NULL
        poppedNode->next = NULL;
        ( *head )->quantity--;
        return poppedNode;
    }
}

/*
====================
reset()
    pops all the elements present in the stack and frees them, leaving only the head;
====================
*/

void reset ( NodeStackHead **head ) { // clears stack
    for(NodeStack *p = pop(head); p != NULL; p = pop(head)) { //iterates over the stack, popping each element until the head points to NULL
        free(p);  // frees the current element
    }
}

/*
====================
listStack()
    Lists what elements are present in the stack
====================
*/

void listStack( NodeStackHead **head ) {
    NodeStackHead *newHead = createHead( ); // new head to insert the read elements
    int totalQuantity = ( *head )->quantity;
    printf( "There are %d elements in the stack \n", ( *head )->quantity );
    for ( int i=0 ; i<totalQuantity ; i++ ) {
        NodeStack *poppedElement = pop( head );
        printf("- Value: %d\n", poppedElement->value );
        push( &( newHead ), poppedElement ); //insert the popped elements into the new head
    }
    for ( int i=0 ; i<totalQuantity ; i++ ) {
        NodeStack *poppedElement = pop( &newHead );
        push( head, poppedElement ); //insert the popped elements back into head in the right order
    }
    free( newHead );
}