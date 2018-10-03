#include<stdio.h>
#include<stdlib.h>
#include "Retangulo.h" //inclui minha interface

int main(){
    int *ret, a, b, res;

    alocacao(ret);

    printf("Digite um numero: ");
    scanf("%i", &a);

    printf("Digite outro numero: ");
    scanf("%i", &b);

    res = calcularRetangulo(ret, &a, &b);
    printf("\nA area do triangulo %i * %i = %i \n", a, b, res);

    liberaAlocacao(ret);
}
