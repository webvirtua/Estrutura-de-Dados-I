#include <stdio.h>
#include <stdlib.h>
#include "Compara.h"

Pilha* criaAlocacao(){
    Pilha *p;
    p = (Pilha*)malloc(sizeof(struct pilha));
    if(p = NULL)
        p->qtd = 0;
    return p;
}

void liberaAlocacao(Pilha* p){
    free(p);
    printf("Memoria liberada!");
}

void inserePalavra(Pilha* p, struct palavra letras){
    if(p == NULL){
        return 0;
        printf("P = NULL");
    }
    if(p->qtd == 4){//pilha cheia
        return 0;
        printf("P < 4");
    }

    p->letras[4] = letras;
    p->qtd++;
    printf("Quantidade = %i", p->qtd);

    //printf("Letra %i: %s", i, p->letras[i]);

    printf("--------------------------------");

    return 1;
}
