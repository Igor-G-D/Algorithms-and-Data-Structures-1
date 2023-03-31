#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int main(  )
{
    TreeHead *head = createTreeHead();

    // int teste[12] = {5,4,7,10,43,5,11,8,9,12,-3, 6};

    srand(1);
    for(int i=0;i<40;i++) {
        insertTreeNode(&(head->root), createTreeNode(rand()%100));
    }
    // printf("Pre: ");
    // printPreOrder(head->root);
    // printf("\n");
    printf("Pre: ");
    printPreOrder(head->root);
    printf("\n");

    removeTreeNode(&(head->root), 83);
    
    printf("Pre: ");
    printPreOrder(head->root);
    printf("\n");

    removeTreeNode(&(head->root), 45);

    printf("Pre: ");
    printPreOrder(head->root);
    printf("\n");

    removeTreeNode(&(head->root), 2);

    printf("Pre: ");
    printPreOrder(head->root);
    printf("\n");

    searchTree(head->root, 45);
    searchTree(head->root, 82);

}
