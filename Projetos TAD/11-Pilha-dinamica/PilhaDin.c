#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h" //inclui os Protótipos

Pilha* cria_Pilha(){
    Pilha* pi = (Pilha*)malloc(sizeof(Pilha));
    if(pi != NULL)
        *pi = NULL; //indica que não tem nenhum elemento na pilha
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

int consulta_topo_Pilha(Pilha* pi){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;

    Elem* no = *pi;

    printf("---------------Mostra registro do topo----------------\n");
    printf("\nMemoria NO: %i\n", no);
    printf("\nMemoria NO->prox: %i\n", no->prox);
    printf("Matricula: %d\n",no->dados.matricula);
    printf("Nome: %s\n",no->dados.nome);
    printf("Notas: %f %f %f\n",no->dados.n1,
                               no->dados.n2,
                               no->dados.n3);
    printf("---------------Mostra registro do topo----------------\n");
    no = no->prox;

    return 1;
}

int insere_Pilha(Pilha* pi, struct aluno al){
    if(pi == NULL)
        return 0;
    Elem* no; //cria um endereço tipo Elem* no
    no = (Elem*)malloc(sizeof(Elem)); //com o tamanha certo do struct
    if(no == NULL)
        return 0;
    no->dados = al; //recebe os dados de uma posição do vetor
    //recebe o endereço de memoria pi, mas muda o numero, porque no limita o tamanha de memoria alocada, o tamanho quando cria e o tamanha do nó são diferentes
    no->prox = (*pi); //no primeiro registro não recebe nada, esta vazio,
    *pi = no;
    return 1;
}

int remove_Pilha(Pilha* pi){
    Pilha_vazia(pi);

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

int Pilha_cheia(Pilha* pi){ //não existe pilha cheia na alocação dinâmica, é só pra manter comparação com pilha estática
    return 0;
}

int Pilha_vazia(Pilha* pi){
    if(*pi == NULL || pi == NULL || *pi == 0)
        printf("A Pilha esta Vazia\n\n");
        return 1;
    return 0;
}

void imprime_Pilha(Pilha* pi){
    Pilha_vazia(pi);
    if(pi == NULL)
        return;
    Elem* no = *pi;
    while(no != NULL){
        printf("\nMemoria NO: %i\n", no);
        printf("\nMemoria NO->prox: %i\n", no->prox);
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        no = no->prox;
        printf("\n no imprime no recebe no->prox: %i\n", no);
        printf("-------------------------------\n");
    }
}
