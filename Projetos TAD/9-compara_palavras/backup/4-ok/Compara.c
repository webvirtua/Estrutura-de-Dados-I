#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Compara.h"

Pilha* cria_Pilha(){
    Pilha *pi;
    pi = (Pilha*) malloc(sizeof(struct pilha));
    if(pi != NULL)
        pi->qtd = 0;
    return pi;
}

void libera_Pilha(Pilha* pi){
    free(pi);
}

int insere_Pilha(Pilha* x, struct aluno al){
    if(x == NULL)
        return 0;
    if(x->qtd == LETRAS)//pilha cheia
        return 0;
    x->dados[x->qtd] = al;
    x->qtd++;
    return 1;
}

int compara_Pilha(Pilha* x, Pilha* y){
    int verifica = 0;
    int i;

    for(i = 0; i < LETRAS; i++){
        if(strcmp(x->dados[i].nome, y->dados[i].nome) == 0){
            verifica += 1;
        }
    }

    if(verifica == LETRAS){
        printf("\n\nString X tem a mesma forma de Y\n");
    }else{
        printf("\n\nString X nao tem a mesma forma de Y\n");
    }

    return 1;
}

int tamanho_Pilha(Pilha* pi){
    if(pi == NULL)
        return -1;
    else
        return pi->qtd;
}

void imprime_Pilha(Pilha* pi){
    if(pi == NULL)
        return;
    int i;
    for(i = pi->qtd - 1; i >= 0; i--){
        printf("%s",pi->dados[i].nome);
    }
}
