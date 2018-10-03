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

int pega_Pilha(Pilha* x, struct aluno al){
    if(x == NULL)
        return 0;
    if(x->qtd == LETRAS)//pilha cheia
        return 0;
    x->dados[x->qtd] = al;
    x->qtd++;
    return 1;
}

char consulta_topo_Pilha(Pilha* x, Pilha* y){
    char temp;
    int i;

    printf("\nPilha X no pega topo = ");
    for(i = x->qtd - 1; i >= 0; i--){
        printf("%s",x->dados[i].nome);
    }

    printf("\nPilha Y no pega topo = ");
    for(i = y->qtd - 1; i >= 0; i--){
        printf("%s",y->dados[i].nome);
    }

    temp = x->dados[i].nome;
    printf("\nTemp = %c", temp);

    if(x == NULL || x->qtd == 0)
        return 0;
    x->dados[x->qtd-1];

    printf("\npega o topo: %c\n", x->dados[x->qtd-1]);
    //return pi->dados[pi->qtd-1];
}

void transfere_Pilha(Pilha* z, Pilha* x){
    char aux[LETRAS];
    if(z == NULL)
        return;
    int i;
    for(i = z->qtd - 1; i >= 0; i--){
        printf("z: %s ",z->dados[i].nome);
        printf("x: %s ",x->dados[i].nome);
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
