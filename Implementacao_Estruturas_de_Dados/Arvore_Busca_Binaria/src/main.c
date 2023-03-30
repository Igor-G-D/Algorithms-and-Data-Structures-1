#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int main(  )
{
    TreeHead *head = createTreeHead();

    // int teste[12] = {5,4,7,10,43,5,11,8,9,12,-3, 6};

    srand(50);

    for(int i=0;i<20;i++) {
        insertTreeNode(&(head->root), createTreeNode(rand()%100));
    }

    // removeTreeNode(&(head->root), -3);
    // removeTreeNode(&(head->root), 7);
    // removeTreeNode(&(head->root), 10);
}
