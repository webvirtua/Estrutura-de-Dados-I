#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Compara.h"

Pilha* cria_Pilha(){
    Pilha *pi;
    pi = (Pilha*)malloc(sizeof(struct pilha));
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

    x->dados[x->qtd] = al; //aqui é inserido assim aluno->dados[1] = al e al é um item do vetor no main a[letras]
    x->qtd++;
    return 1;
}

int remove_Pilha(Pilha* pi){ //não é apagado o registro só o acesso é restringido pelo qtd
    if(pi == NULL || pi->qtd == 0){
        printf("\n\nPilha Vazia: ");
    }else{
        pi->qtd--;
    }
}

int inverte_Pilha(Pilha* x, Pilha* temp, Pilha* copia){
    int i;

    if(x == NULL || temp == NULL || copia == NULL){
        return;
    }

    for(i = x->qtd - 1; i >= 0; i--){
        insere_Pilha(temp, x->dados[i]);
    }

    for(i = x->qtd - 1; i >= 0; i--){
        insere_Pilha(copia, temp->dados[i]);
    }
}

int compara_Pilha(Pilha* x, Pilha* y){ //strcopy(x->dados[i].nome, y->dados[i].nome) assim é usado pra copiar um struct
    int i,  verifica = 0;

    for(i = LETRAS - 1; i >= 0; i--){
        if(strcmp(x->dados[i].nome, y->dados[i].nome) == 0){
            verifica += 1;
        }
    }

    strcpy(x->dados[2].nome, y->dados[2].nome);

    if(verifica == LETRAS){
        printf("String X tem a mesma forma de Y\n");
    }else{
        printf("String X nao tem a mesma forma de Y\n");
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
        printf("   %s\n",pi->dados[i].nome);
    }
}
