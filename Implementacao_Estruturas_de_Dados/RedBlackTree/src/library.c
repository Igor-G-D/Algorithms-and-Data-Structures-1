#include <stdio.h>
#include <stdlib.h>
#include "library.h"

TreeHead * createTreeHead ( ) {
    TreeHead * newHead = ( TreeHead * )malloc( sizeof( TreeHead ) );
    newHead->root = NULL;
    return newHead;
}

TreeNode * createTreeNode (int value) {
    TreeNode * newNode = ( TreeNode * )malloc( sizeof( TreeNode ) );
    newNode->value = value;
    newNode->color = 1; //red
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void insertTreeNode ( TreeHead *head, TreeNode *newNode ) {
    if ( head->root == NULL ) {
        newNode->color = 0; // black
        head->root = newNode;
    } else {
        insertTreeNodeRecursive( head->root, &(head->root), newNode );
    }
}

void insertTreeNodeRecursive ( TreeNode * parent, TreeNode ** p,  TreeNode *newNode ) {
    if( (*p) == NULL ) { // found the place to insert
        if(parent->color == 0) { // parent is black, insert and exit;
            newNode->parent = parent;
            (*p) = newNode;
        }
    } else if ( (*p)->value > newNode->value) {
        insertTreeNode( (&((*p)->left)), newNode );
    }  else if ( (*p)->value < newNode->value ) {
        insertTreeNode( (&((*p)->right)), newNode );
    } else { // means that the values are equal
        printf("Value already in the tree! (%d)\n", newNode->value);
    }

    balancingAVL(p);
}

void fixRedBlackTree ( TreeNode **p ) {
    
}

TreeNode * deleteLowest(TreeNode ** p) { // looks for the element with the lowest value, deletes it from the tree and returns its value
    if((*p)->left != NULL) {
        TreeNode *lowest = deleteLowest((&((*p)->left)));
        balancingAVL(p); // needs to check since removing an element may cause an imbalance
        return lowest;
    } else {
        TreeNode * temp = (*p);
        (*p) = (*p)->right;
        return temp;
    }
} 

void rotationLL ( TreeNode ** p) {
    TreeNode *temp = (*p)->left;
    (*p)->left = (*p)->left->right;
    temp->right = (*p);
    (*p) = temp;
}

void rotationRR ( TreeNode ** p) {
    TreeNode *temp = (*p)->right;
    (*p)->right = (*p)->right->left;
    temp->left = (*p);
    (*p) = temp;
}

void rotationRL ( TreeNode **p ) {
    rotationLL(&((*p)->right));
    rotationRR(p);
}

void rotationLR ( TreeNode **p ) {
    rotationRR(&((*p)->left));
    rotationLL(p);
}

void colorFlip(TreeNode *node)
{
    node->color = 1-node->color; // flips between 1 an 0
    node->left->color = 1-node->left->color;// flips between 1 an 0
    node->right->color = 1-node->right->color;// flips between 1 an 0
}

void printInOrder ( TreeNode *p ) {

    if( p == NULL) {
        return;
    } else {
        printInOrder( p->left );

        printf( "[%d]", p->value );

        printInOrder( p->right ); 
    }
}

void printPostOrder ( TreeNode *p ) {
    
    if( p == NULL) {
        return;
    } else {
        printPostOrder( p->left );

        printPostOrder( p->right ); 

        printf( "[%d]", p->value );
    }
}

void printPreOrder ( TreeNode *p ) {
        
    if( p == NULL) {
        return;
    } else {
        printf( "[%d]", p->value );

        printPreOrder( p->left );

        printPreOrder( p->right ); 
    }
}

void searchTree( TreeNode * p, int value ) {
    if (p == NULL) {
        printf("Searched value not found! (%d)\n", value);
        return;
    } else if (value > p->value) { // if value is bigger than the current node's value, search on the right subtree
        searchTree(p->right, value);
    } else if (value < p->value) {// if value is smaller than the current node's value, search on the right subtree
        searchTree(p->left, value);
    } else {
        printf("Searched value was found inside the tree! (%d)\n", value); // if both of the previous conditions are false, and the element isn't NULL, means that the values are equal
    }
}