#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "library.h"

void randomArray(int *array, int size) {
    srand(time(NULL)); // seed for random values
    for (int i = 0; i < size; i++) {
        array[i] = rand()%100; // fill the current pos with a random value between 0 and 100
    }
}

void selectionSort ( int *array, int size ) {
    int i, j, temp;
    int minIndex = 0;
    for ( i = 0 ; i < size ; i++ ) { // iterate through array
        minIndex = i; 
        for( j = i+1 ; j < size ; j++ ) { // find lowest value in the rest of the array
            if ( array[minIndex] > array[j] ) {
                minIndex = j; 
            } 
        }
        temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp; // switch the positions of the lowest value found and the one currently being pointed to by i
    }
}

void quickSort( int *array, int start, int end ) {
    int i;
    int pivotPos = end-1;
    int lower = start;

    if(start == end) {
        return;
    }

    for (i = start; i < end; i++) {
        if (array[i] < array[pivotPos]) { // orders so that all elements that are lower are on the left, and all the elements that are higher are on the right
            int temp = array[i]; // for each element that is less than the pivot element, the function swaps it with the element at the lower index
            array[i] = array[lower];
            array[lower] = temp;
            lower++; 
        }
    }
    // after getting through the array, puts the index in the correct position
    int temp = array[pivotPos];
    array[pivotPos] = array[lower];
    array[lower] = temp;

    pivotPos = lower;

    // recursion for the sub arrays
    quickSort(array, start, pivotPos);
    quickSort(array, pivotPos + 1, end);

}