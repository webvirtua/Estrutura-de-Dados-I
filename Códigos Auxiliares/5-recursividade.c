#include <stdio.h>
#include <stdlib.h>
int sequencia_interativa(int n){
    int seq;

    for(int i = 2; i < n; i++){
        seq = (n - 1) + 3;
    }
    return seq;
}

/*int sequencia_recursiva(int n){
    if(n <= 1){
        return 1;
    }else{
        return n * sequencia_recursiva(n - 1);
    }
}*/
int main() {
    int n = 2, resultado, recursivamente;

    resultado = sequencia_interativa(n);
    //recursivamente = sequencia_recursiva(n);

    printf("Resultado da sequencia: %d", resultado);

    printf("\n\n-------------------------------------\n\n");

    //printf("Resultado do Fatorial: %d\n\n", recursivamente);
}
