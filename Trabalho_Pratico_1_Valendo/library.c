#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "library.h"

/*
====================
judgeCircle

Given a string of characters containing 'U' for up, 'D' for down, 'R' for right, 'L' for left, returns true if those moves will end back in the origin, false if not
====================
*/

int judgeCircle( char * moves ) {
    int valueX = 0;
    int valueY = 0;

    for ( char *word = moves ; *word != '\0' ; word += sizeof( char ) ) { //iterates over each character of the string with a pointer, until it finds the '\0' end character
        if ( *word == 'U' ) { //checks to see which of the 4 letter was chosen, else's are used since if one option is found, it won't be any of the others
            valueY++;
        } else if ( *word == 'D' ) {
            valueY--;
        } else if ( *word == 'L' ) {
            valueX--;
        } else  if ( *word == 'R' ){
            valueX++;
        }
    }
    if ( valueX == 0 && valueY == 0 ) { //if both values are 1, mean that it is in the position 0,0
        return 1;
    } else {
        return 0;
    }
}