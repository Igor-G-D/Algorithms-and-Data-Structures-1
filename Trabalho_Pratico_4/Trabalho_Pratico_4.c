#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomArray( int *array, int size );
int* maxSubsequence( int* nums, int numsSize, int k, int* returnSize );

/*
====================
main
    Creates a random test case with the size and subarray size being alterable via two integers, executes and prints them into console
====================
*/


int main ( ) {
    int size = 16;
    int sizeSubArray = 3;

    int test[ size ];
    randomArray( test, size );

    int returnSize;

    int * result = maxSubsequence ( test, size, sizeSubArray, &( returnSize ) ); 
    
    printf( "random array: " );
    for ( int i = 0 ; i < size ; i++ ) {
        printf( "[%d]", test[ i ] );
    }

    printf( "\n result: " );

    for ( int i = 0 ; i < returnSize ; i++ ) {
        printf( "[%d]", result[ i ] );
    }
    printf( "\n" );

    free( result );

    return 0;
}

/*
====================
randomArray
    Fills an array of integers with random integers between -105 and 105
====================
*/

void randomArray ( int *array, int size ) {
    srand( time( NULL ) ); // seed for random values based on current time
    for ( int i = 0 ; i < size ; i++ ) {
        array[ i ] = rand( )%105 - rand( )%105; // fill the current pos with a random value between -105 and 105
    }
}

/*
====================
randomArray
    Recieves an array of integers, and a number k, returns the subarray with length k that has the highest sum
====================
*/

int* maxSubsequence ( int* nums, int numsSize, int k, int* returnSize ) {
    int i,j, temp, highestPos, highestValue;
    for ( i = 0 ; i < ( numsSize - k + 1 ) ; i++ ) { // iterate through every subArray
        temp = 0;
        for ( j = i ; j < ( i + k ) ; j++ ) { // sum of the subArray
            temp += nums[ j ];
        }
        if ( i == 0 ) { // first iteration
            highestValue = temp;
            highestPos = i;
        } else {
            if ( highestValue < temp ) { // if a higher value is found, store it and the position of the subarray
                highestValue = temp;
                highestPos = i;
            } 
        }
    }
    
    int * returnArray = ( int * ) malloc ( sizeof( int ) * k );

    for( i = 0 ; i < k ; i++ ) {
        returnArray[ i ] = nums[ highestPos + i ]; // creates new array and returns the values that were found in the highest subArray
    }
    
    *returnSize = k;

    return returnArray;
}