#include<stdio.h>
#include<stdlib.h>
#include "Retangulo.h" //inclui minha interface

int main(){
    int *quadras, a, b, res;

    alocacao(quadras);

    printf("Digite um numero: ");
    scanf("%i", &a);

    printf("Digite outro numero: ");
    scanf("%i", &b);

    res = calcularRetangulo(quadras, a, b);
    printf("\nA area do triangulo %i * %i = %i \n", a, b, res);
}
