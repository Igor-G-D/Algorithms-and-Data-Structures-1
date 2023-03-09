#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "library.h"

int Permutacao(int n, int rep_1, int rep_2) {

    int result;
    if(n == rep_1 || n == rep_2) {
        return 1;
    } else {
        result = (Fatorial(n))/(Fatorial(rep_1)*Fatorial(rep_2));
    }

    return result;

}

int Fatorial(int n) {
    if(n < 0) {
        return -1;
    } else if (n == 0) {
        return 1;
    } else {
        int temp = 1;
        for(int i=1;i<=n;i++) {
            temp = temp * i;
        }
        return temp;
    }
}