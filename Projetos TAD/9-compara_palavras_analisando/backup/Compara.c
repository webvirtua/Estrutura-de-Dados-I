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

int remove_Pilha(Pilha* pi){
    if(pi == NULL || pi->qtd == 0)
        return 0;
    pi->qtd--;
    return 1;
}

int inverte_Pilha(Pilha* x, Pilha* temp, Pilha* copia){
    if(x == NULL)
        return;
    int i;

    printf("\n\nImprime X no inverte: ");
    imprime_Pilha(x);

    for(i = LETRAS -1 ; i >= 0; i--)
        strcpy(temp->dados[i].nome, x->dados[i].nome);
    printf("\n\n===copia==>%s\n", temp->dados[3].nome);
    printf("\n\nImprime tempo no inverte: ");
    imprime_Pilha(temp);


    for(i = 0; i < LETRAS; i++) {


        insere_Pilha(copia, x->dados[i]);
    }


    printf("\n\nImprime copia no inverte: ");
    imprime_Pilha(copia);

    for(i = temp->qtd - 1; i >= 0; i--){
        printf("%s",temp->dados[i].nome);
    }
}

int compara_Pilha(Pilha* x, Pilha* y){
    int verifica = 0;
    int i;

    for(i = 0; i < LETRAS; i++){
        if(strcmp(x->dados[i].nome, y->dados[i].nome) == 0){
            verifica += 1;
        }
    }

    strcpy(x->dados[2].nome, y->dados[2].nome);
    printf("\n\n=====>%s\n", x->dados[2].nome);

    if(verifica == LETRAS){
        printf("\n\nString X tem a mesma forma de Y\n");
    }else{
        printf("\n\nString X nao tem a mesma forma de Y\n");
    }

    return 1;
}

int tamanho_Pilha(Pilha* pi){
    if(pi == NULL){
        return -1;
    }else if(pi->qtd = 4){
        printf("\n\nLista Cheia\n");
        return -1;
    }else if(pi->qtd < 0){
        printf("\n\nPilha Vazia\n");
        return -1;
    }else{
        return pi->qtd;
    }
}

void imprime_Pilha(Pilha* pi){
    if(pi == NULL)
        return;
    int i;
    for(i = pi->qtd - 1; i >= 0; i--){
        printf("%s",pi->dados[i].nome);
    }
}
