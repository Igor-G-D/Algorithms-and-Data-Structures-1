#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "library.h"

int main ( ) {
	printf( "LL, expected false, result: %d\n", judgeCircle( "LL" ));
	printf( "UD, expected true, result: %d\n", judgeCircle( "UD" ) );
	printf( "URURDDLL, expected true, result: %d\n", judgeCircle( "URURDDLL" ) );
	printf( "URURDDLLR, expected false, result: %d\n", judgeCircle( "URURDDLLR" ) );
	printf( "URURURRRRUUULDULLD, expected false, result: %d\n", judgeCircle( "URURURRRRUUULDULLD" ) );
	printf( "URULULDLDDDDRRUU, expected true, result: %d\n", judgeCircle( "URULULDLDDDDRRUU" ) );
	printf( "(empty string), expected true, result: %d\n", judgeCircle( "" ) );
	printf( "UUDDLL, expected false, result: %d\n", judgeCircle( "UUDDLL" ) );
	printf( "UUDDLLRR, expected true, result: %d\n", judgeCircle( "UUDDLLRR" ) );
	printf( "URULLDDDRRULRR, expected false, result: %d\n", judgeCircle( "URULLDDDRRULRR" ) );

	return 0;
}