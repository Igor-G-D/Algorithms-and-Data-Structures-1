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
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void insertTreeNode ( TreeNode **p, TreeNode *newNode ) {
    if( (*p) == NULL ) {
        (*p) = newNode;
        return;
    } else if ( (*p)->value > newNode->value) {
        insertTreeNode( (&((*p)->left)), newNode );
        return;
    }  else if ( (*p)->value < newNode->value ) {
        insertTreeNode( (&((*p)->right)), newNode );
        return;
    } else { // means that the values are equal
        printf("Value already in the tree! (%d)\n", newNode->value);
        return;
    }
}

void removeTreeNode ( TreeNode **p, int value ) {
    if ( (*p)->value > value) {
        removeTreeNode((&((*p)->left)), value );
    }  else if ( (*p)->value < value ) {
        removeTreeNode((&((*p)->right)), value );
    } else { // values are equal
        if((*p)->left == NULL && (*p)->right == NULL) { //means that it's a leaf
            TreeNode *temp = (*p);
            (*p) = NULL;
            free(temp);
            return;
        } else if ((*p)->right == NULL && (*p)->left) { // means it had a left element but not a right element
            TreeNode *temp = (*p);
            (*p) = (*p)->left;
            free(temp);
        } else if ((*p)->left == NULL && (*p)->right) { // means it had a right element but not a right element
            TreeNode *temp = (*p);
            (*p) = (*p)->right;
            free(temp);
        } else if((*p)->left && (*p)->right) { // means that it has both a left and right element
            
            // if(height((*p)->left) > height((*p)->right)) { // means the height of the left element is higher than the height of the right element
            //     TreeNode *temp = (*p);
            //     (*p) = deleteHighest((&((*p)->left))); // changes the value of the element to be removed to the value of the highest element on its left
            //     (*p)->left = temp->left;
            //     (*p)->right = (*p)->right;
            //     free(temp);
            // } else { // means the height of the right element is higher or equal to the height of the right element
            //     TreeNode *temp = (*p);
            //     (*p) = deleteLowest((&((*p)->right))); // changes the value of the element to be removed to the value of the lowest element on its right
            //     (*p)->left = temp->left;
            //     (*p)->right = (*p)->right;
            //     free(temp);
            // }

            TreeNode *temp = (*p);
            (*p) = deleteHighest((&((*p)->left))); // changes the value of the element to be removed to the value of the highest element on its left
            (*p)->left = temp->left;
            (*p)->right = (*p)->right;
        } 
    }
}

int height( TreeNode *p ) {
    int rightHeight = 0;
    int leftHeight = 0;
    if(p == NULL) {
        return 0;
    } else {
        rightHeight = height(p->right);
        leftHeight = height(p->left);
    }

    if(rightHeight >= leftHeight) { // if the height of the right node is higher, the height of the root node would be height(right) +1. If the heights are the same, doesn't matter if right or left is used
        return (rightHeight+1);
    } else {
        return (leftHeight+1);// if the height of the left node is higher, the height of the root node would be height(left) +1.
    }
}

int balancingFactor( TreeNode *p ) {
    return ((height(p->left)) - (height(p->right)));
}

TreeNode * deleteHighest(TreeNode ** p) { // looks for the element with the lowest value, deletes it from the tree and returns its value
    if((*p)->right != NULL) {
        deleteHighest((&((*p)->right)));
    }
    TreeNode * temp = (*p);
    p = NULL;
    return temp;
} 

TreeNode * deleteLowest(TreeNode ** p) { // looks for the element with the lowest value, deletes it from the tree and returns its value
    if((*p)->left != NULL) {
        return deleteLowest((&((*p)->left)));
    } else {
        TreeNode * temp = (*p);
        (*p) = NULL;
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
    rotationLL(&((*p)->left));
    rotationRR(p);
}

void rotationLR ( TreeNode **p ) {
    rotationRR(&((*p)->right));
    rotationLL(p);
}