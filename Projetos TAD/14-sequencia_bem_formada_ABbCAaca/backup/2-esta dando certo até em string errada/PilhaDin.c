
#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h" //inclui os Protótipos

Pilha* cria_Pilha(){
    Pilha* pi = (Pilha*)malloc(sizeof(Pilha));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}

void libera_Pilha(Pilha* pi){
    if(pi != NULL){
        Elem* no;
        while((*pi) != NULL){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    }
}

int consulta_topo_Pilha(Pilha* pi, struct item *al){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    *al = (*pi)->dados;
    return 1;
}

int insere_Pilha(Pilha* pi, struct item al){
    if(pi == NULL)
        return 0;
    Elem* no;
    no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*pi);
    *pi = no;

    return 1;
}

int verifica_Formacao(Pilha* pi1, Pilha* pi2){
    int verifica, t1, t2;

    if(pi1 == NULL || pi2 == NULL){
        return 0;
    }else{
        Elem* no1 = *pi1;
        Elem* no2 = *pi2;

        while(no1 != NULL || no2 != NULL){
            t1 = no1->dados.c, t2 = no2->dados.c;
            no1 = no1->prox;
            no2 = no2->prox;

            if((t2 - t1) != 32){
                return 0;
            }
        }
        return 1;
    }
}

int remove_Pilha(Pilha* pi){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    Elem* no = *pi;
    *pi = no->prox;
    free(no);
    return 1;
}

int tamanho_Pilha(Pilha* pi){
    if(pi == NULL)
        return 0;
    int cont = 0;
    Elem* no = *pi;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int Pilha_cheia(Pilha* pi){
    return 0;
}

int Pilha_vazia(Pilha* pi){
    if(pi == NULL)
        return 1;
    if(*pi == NULL)
        return 1;
    return 0;
}

void imprime_Pilha(Pilha* pi){
    if(pi == NULL)
        return;
    Elem* no = *pi;
    while(no != NULL){
        printf("\nItem=>: %c\n",no->dados.c);
        no = no->prox;
    }
    printf("\n");
}

void invert_Pilha(Pilha* pi, int tam){
    char seq[20];
    int i = 0;
    struct item elemento;

    if(pi == NULL)
        return;
    Elem* no = *pi;
    while(no != NULL){
        seq[i] = no->dados.c;
        elemento.c = seq[i];
        no = no->prox--;
        i++;
    }
    *pi = no;

    for (i = 0; i < tam; ++i){
        elemento.c = seq[i];
        insere_Pilha(pi, elemento);
    }
}
