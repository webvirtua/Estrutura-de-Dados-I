#include <stdio.h>
#include <stdlib.h>
int fatorial_interativo(int n){
    int fat = 1;

    for(int i = n; i > 0; i--){
        fat *= i;
    }

    return fat;
}

int fatorial_recursivo(int n){
    if(n <= 1){
        return 1;
    }else{
        return n * fatorial_recursivo(n - 1);
    }
}
int main() {
    int n = 5, resultado, recursivamente;

    resultado = fatorial_interativo(n);
    recursivamente = fatorial_recursivo(n);

    printf("---------------funcao interativa comum----------------------\n\n");

    printf("Resultado do Fatorial: %d", resultado);

    printf("\n\n---------------funcao recursiva----------------------\n\n");

    printf("Resultado do Fatorial: %d\n\n", recursivamente);
}
