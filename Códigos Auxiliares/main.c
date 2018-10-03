#include <stdio.h>
#include <stdlib.h>
int sequencia_interativa(int n){
    int seq = 2;

    for(int i = 2; i <= n; i++){
        seq = (n - 1) + 3;
    }
    return seq;
}

int sequencia_recursiva(int n){
    if(n < 2){
        return 0;
    }else{
        return (n - 1) + 3;
    }
}
int main() {
    int n = 3, resultado, recursivamente;

    resultado = sequencia_interativa(n);
    recursivamente = sequencia_recursiva(n);

    printf("---------------funcao interativa comum----------------------\n\n");

    printf("Resultado do Fatorial: %d", resultado);

    printf("\n\n---------------funcao recursiva----------------------\n\n");

    printf("Resultado do Fatorial: %d\n\n", recursivamente);
}
