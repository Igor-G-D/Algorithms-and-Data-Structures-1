#include <stdio.h>
#include "library.h"

int main()
{
    int test[10];
    randomArray(test, 10);

    quickSort(test, 0, 10);

    return 0;
}
