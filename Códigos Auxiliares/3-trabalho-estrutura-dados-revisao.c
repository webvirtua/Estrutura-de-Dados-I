#include <stdio.h>
int main() {
    int sN, i, s1 = 1, n = 2;

    for(i = 0; i < 4; i++){
        sN = (n-1) + 3;

        printf("Resultado: %d\n", sN);
        n = n + 1;
    }
}
/*
n=2 e 4
n=3 e 5
n=4 e 6
n=5 e 7
n=6 e 8
n=15 e 17
n=16 e 18
*/
