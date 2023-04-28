#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getLowest(int * array, int start, int end);
void randomArray( int *array, int size );
int* maxSubsequence( int* nums, int numsSize, int k, int* returnSize );
void selectionSort ( int *array, int size , int *originalIndex);

/*
====================
main
    Creates a random test case with the size and subarray size being alterable via two integers, executes and prints them into console
====================
*/


int main ( ) {
    int size = 7;
    int sizeSubArray = 7;

    int test[ 7 ] = {-8,-94,-30,-98,-27,62,26};
    // int test[ 2 ] = {50, -75};
    //randomArray( test, size );

    int returnSize;

        
    printf( "random array: " );
    for ( int i = 0 ; i < size ; i++ ) {
        printf( "[%d]", test[ i ] );
    }

    int * result = maxSubsequence ( test, size, sizeSubArray, &( returnSize ) ); 

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

    int i,j;
    int originalIndex[ numsSize ];

    selectionSort ( nums, numsSize , originalIndex ); // orders the array and returns an array that stores all the original positions of the elements

    int * returnArray = ( int * ) malloc ( sizeof( int ) * k );

    for( i = 0; i < k ; i++ ) {
        int tempindex = getLowest( originalIndex, numsSize-k, numsSize );
        returnArray[ i ] = nums[ tempindex ];
    }
    
    *returnSize = k;

    return returnArray;
}

/*
====================
quickSort
    Recieves an array of integers, and orders it using the selection sort, and also stores the positions of the original array
====================
*/

void selectionSort ( int *array, int size , int *originalIndex) {
    int i, j, temp, minIndex;
    for ( i = 0 ; i < size ; i ++ ) {
        originalIndex[i] = i;
    }

    for ( i = 0 ; i < size ; i++ ) {
        minIndex = i;
        for ( j = i + 1 ; j < size ; j++ ) {
            if ( array[ minIndex ] > array[ j ]) {
                minIndex = j;
            }
        }
        temp = array[ i ];
        array[ i ] = array[ minIndex ];
        array[ minIndex ] = temp;

        temp = originalIndex[ i ]; // swaps the indexes along with the swapping from the sorting
        originalIndex[ i ] = originalIndex[ minIndex ];
        originalIndex[ minIndex ] = temp;
    }
}

/*
====================
getLowest
    Recieves an array of integers, a pointer to the start and another to the end of where it should iterate through, returns the lowest non negative number and sets the number chosen to -1 in the array
====================
*/

int getLowest ( int * array, int start, int end ) {// returns the lowest non negative value's position and makes that original value to -1, -1 if no positive values were fonunt
    int i, lowestPos;
    int lowest = -1;
    for ( int i = start ; i < end ; i++ ) {
        if ( array[ i ] >= 0 ) {
            if ( lowest == -1 ) {
                lowest = array[ i ];
                lowestPos = i;
            }
            if ( array[ i ] < lowest ) {
                lowest = array[ i ];
                lowestPos = i;
            }
        }
    }
    if ( lowestPos < 0 ) {
        return -1;
    }
    array[ lowestPos ] = -1;
    return lowestPos;
}