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
    printf("Memoria liberada\n");
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

int inverte_Pilha(Pilha* pi, struct aluno al){
    if(pi == NULL)
        return 0;
    if(pi->qtd == LETRAS)//pilha cheia
        return 0;
    pi->dados[pi->qtd] = al;
    pi->qtd++;
    return 1;
}

int compara_Pilha(Pilha* x, Pilha* y){
    int verifica = 0;
    printf("\n======Compara Pilha=======");

    int i;
    for(i = 0; i < LETRAS; i++){
        if(x->dados[i].nome != y->dados[i].nome){
            printf("\nX: %s = Y: %s", x->dados[i].nome, y->dados[i].nome);
            //verifica = 1;
        }else{
            //verifica = 0;
        }

        if(strcmp(x->dados[i].nome, y->dados[i].nome) == 0){
            verifica = 0;
        }else{
            verifica = 1;
        }
    }

    if(verifica == 0){
        printf("\n\nString X tem a mesma forma de Y");
    }else{
        printf("\n\nString X nao tem a mesma forma de Y");
    }
     printf("\nVerifica tem valor: %i", verifica);

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
