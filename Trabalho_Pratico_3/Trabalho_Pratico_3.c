#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode TreeNode;
int height( struct TreeNode * p );
void insertTree( struct TreeNode **p, int value );
int diameterOfBinaryTree( TreeNode* root );
void freeTree( TreeNode *p );

// you can find the highest path by finding which element has the highest sun of heights in their child nodes

/*
====================
main
    Creates all the test cases, executes and prints them into console
====================
*/

int main ( int argc, char const *argv[] )
{

    // test cases    
    TreeNode * head1 = ( TreeNode* )malloc( sizeof ( TreeNode ) );
    TreeNode * head2 = ( TreeNode* )malloc( sizeof ( TreeNode ) );
    TreeNode * head3 = ( TreeNode* )malloc( sizeof ( TreeNode ) );
    TreeNode * head4 = ( TreeNode* )malloc( sizeof ( TreeNode ) );
    TreeNode * head5 = ( TreeNode* )malloc( sizeof ( TreeNode ) );

    head1->left = NULL;
    head1->right = NULL;
    head1->val = 0;

    head2->left = NULL;
    head2->right = NULL;
    head2->val = 0;

    head3->left = NULL;
    head3->right = NULL;
    head3->val = 0;

    head4->left = NULL;
    head4->right = NULL;
    head4->val = 0;

    head5->left = NULL;
    head5->right = NULL;
    head5->val = 0;

    int test1[ 10 ] = { 10,5,4,3,2,1,6,7,8,9 };
    for ( int i = 0 ; i < 10 ; i++ ) {
        insertTree( &( head1->left ), test1[ i ]); // left of the head points to the actual tree
    }

    int test2[ 5 ] = { 4,2,1,3,5 };
    for ( int i = 0 ; i < 5 ; i++ ) {
        insertTree(&(head2->left), test2[ i ]); // left of the head points to the actual tree
    }

    int test3[ 1 ] = { 4 };
    for ( int i = 0 ; i < 1 ; i++ ) {
        insertTree( &( head3->left ), test3[ i ]); // left of the head points to the actual tree
    }

    int test4[ 10 ] = { 10,2,1,0,8,5,6,7,12,15 };
    for ( int i = 0 ; i < 10 ; i++ ) {
        insertTree( &( head4->left ), test4[ i ]); // left of the head points to the actual tree
    }

    int test5[ 7 ] = { 13,12,10,11,15,14,16 };
    for ( int i = 0 ; i < 7 ; i++ ) {
        insertTree( &( head5->left ), test5[ i ]); // left of the head points to the actual tree
    }

    // test cases

    int diameter1 = diameterOfBinaryTree( head1->left );
    int diameter2 = diameterOfBinaryTree( head2->left );
    int diameter3 = diameterOfBinaryTree( head3->left );
    int diameter4 = diameterOfBinaryTree( head4->left );
    int diameter5 = diameterOfBinaryTree( head5->left );

    printf ( "diameter of tree {10,5,4,3,2,1,6,7,8,9} (Expected: 8): %d\n", diameter1 );
    printf ( "diameter of tree {4,2,1,3,5} (Expected: 3): %d\n", diameter2 );
    printf ( "diameter of tree {4} (Expected: 0): %d\n", diameter3 );
    printf ( "diameter of tree {10,2,1,0,8,5,6,7,12,15} (Expected: 7): %d\n", diameter4 );
    printf ( "diameter of tree {13,12,10,11,15,14,16} (Expected: 5): %d\n", diameter5 );

    freeTree( head1 );
    freeTree( head2 );
    freeTree( head3 );
    freeTree( head4 );
    freeTree( head5 );

    return 0;
}

/*
====================
diameterOfBinaryTree()
    Returns the length of the longest path between any two nodes in a binary tree
====================
*/

int diameterOfBinaryTree( TreeNode* root ){ 
    if( root == NULL ) {
        return 0;
    }
    int heightLeft = height( root->left );
    int heightRight = height( root->right );

    int leftNodeDiameter = diameterOfBinaryTree( root->left );
    int rightNodeDiameter = diameterOfBinaryTree( root->right );

    int highestDiameter;

    if ( leftNodeDiameter > rightNodeDiameter ) {
        highestDiameter = leftNodeDiameter;
    } else {
        highestDiameter = rightNodeDiameter;
    }

    if ( highestDiameter < ( heightLeft + heightRight ) ) {
        highestDiameter = ( heightLeft + heightRight );
    } 

    // get the highest value out of the three: diameter of left, diameter of right, diameter of current node

    return highestDiameter;
}

/*
====================
height()
    Calculates and returns the height of a node
====================
*/

int height( TreeNode * p ) { // first, find the height
    if( p == NULL ) {
        return 0;
    }
    int left = height( p->left );
    int right = height( p->right );

    if ( left > right ) { //return highest height
        return ++left; 
    } else {
        return ++right;
    }
}

/*
====================
insertTree()
    Insert values into a binary search tree
====================
*/

void insertTree( TreeNode **p, int value ) {
    
    if ( ( *p ) == NULL ) {
        TreeNode * new = ( struct TreeNode* )malloc( sizeof( TreeNode ) );
        new->left = NULL;
        new->right = NULL;
        new->val = value;
        *p = new;
        return;
    }
    if ( ( *p )->val > value ) {
        insertTree( &( ( *p )->left ), value );
    } else {
        insertTree( &( ( *p )->right ), value );
    }
}

/*
====================
freeTree()
    Frees each node of a tree, including the head, from memory
====================
*/

void freeTree ( TreeNode *p ) { // frees the entire tree recursively
    if ( p == NULL ) {
        return;
    }
    freeTree( p->left );
    freeTree( p->right );

    free( p );
}