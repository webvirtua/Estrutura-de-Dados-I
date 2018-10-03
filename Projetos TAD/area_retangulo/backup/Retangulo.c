#include<stdio.h>
#include<stdlib.h>
#include "Retangulo.h" //inclui minha interface

int alocacao(int *quadras){
    *quadras = (int)calloc(2, sizeof(int));

    if(quadras == NULL){
        printf("Memoria insuficiente");
    }

    return quadras;
}

int calcularRetangulo(int *quadras, int a, int b){
    int res = a * b;

    return res;
}


