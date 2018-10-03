#include<stdio.h>
#include<stdlib.h>
#include "Retangulo.h" //inclui minha interface

int *alocacao(int *ret){
    *ret = (int)calloc(2, sizeof(int));

    if(ret == NULL){
        printf("Memoria insuficiente");
    }

    return ret;
}

void liberaAlocacao(int *ret){
    free(*ret);
}

int calcularRetangulo(int *ret, int *a, int *b){
    int res = *a * *b;

    return res;
}


