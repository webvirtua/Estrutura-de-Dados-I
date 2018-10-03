#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncadDupla.h" //inclui os Protótipos

//Definição do tipo lista
struct elemento{
    struct elemento *ant;
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || pos <= 0)
        return 0;
    Elem *no = *li;
    int i = 1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }
    if(no == NULL)
        return 0;
    else{
        *al = no->dados;
        return 1;
    }
}

int consulta_lista_mat(Lista* li, int mat, struct aluno *al){
    if(li == NULL)
        return 0;
    Elem *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        no = no->prox;
    }
    if(no == NULL)
        return 0;
    else{
        *al = no->dados;
        return 1;
    }
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem *no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL){//lista vazia: insere início
        no->ant = NULL;
        *li = no;
    }else{
        Elem *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
        no->ant = aux;
    }
    return 1;
}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*li);
    no->ant = NULL;
    if(*li != NULL)//lista não vazia: apontar para o anterior!
        (*li)->ant = no;
    *li = no;
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    if((*li) == NULL){//lista vazia: insere início
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return 1;
    }
    else{
        Elem *ante, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ante = atual;
            atual = atual->prox;
        }
        if(atual == *li){//insere início
            no->ant = NULL;
            (*li)->ant = no;
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = ante->prox;
            no->ant = ante;
            ante->prox = no;
            if(atual != NULL)
                atual->ant = no;
        }
        return 1;
    }
}

int remove_lista(Lista* li, int mat){//TERMINAR
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;
    Elem *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        no = no->prox;
    }
    if(no == NULL)//não encontrado
        return 0;

    if(no->ant == NULL)//remover o primeiro?
        *li = no->prox;
    else
        no->ant->prox = no->prox;

    if(no->prox != NULL)//não é o último?
        no->prox->ant = no->ant;

    free(no);
    return 1;
}


int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elem *no = *li;
    *li = no->prox;
    if(no->prox != NULL)
        no->prox->ant = NULL;

    free(no);
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elem *no = *li;
    while(no->prox != NULL)
        no = no->prox;

    if(no->ant == NULL)//remover o primeiro e único
        *li = no->prox;
    else
        no->ant->prox = NULL;

    free(no);
    return 1;
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(Lista* li){
    return 0;
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    Elem* no = *li;
    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");

        no = no->prox;
    }
}

int insere_pos(Lista* li, struct aluno al, int pos) {
    int tam = tamanho_lista(li);
    if(li == NULL)
        return 0;

    printf("Tamanho no tad: %d", tamanho_lista(li));

    Elem *no = *li;

    if (pos == 1){
        insere_lista_inicio(li, al);
    } else if (pos > tam) {
        insere_lista_final(li, al);
    }else {
        int i=0;
        while(no != NULL && ++i != pos){
            no = no->prox;
        }

        Elem *novo = (Elem*) malloc(sizeof(Elem));
        novo->dados = al;

        no->ant->prox = novo;
        novo->ant = no->ant;

        no->ant = novo;
        novo->prox = no;
    }

    return 0;
}

int deleta_pos(Lista* li, struct aluno al, int pos) {
    int tam = tamanho_lista(li);
    if(li == NULL)
        return 0;

    printf("Tamanho no tad: %d", tamanho_lista(li));

    Elem *no = *li;

    if (pos == 1){
        insere_lista_inicio(li, al);
    } else if (pos > tam) {
        insere_lista_final(li, al);
    }else {
        int i=0;
        while(no != NULL && ++i != pos){
            no = no->prox;
        }

        Elem *novo = (Elem*) malloc(sizeof(Elem));
        novo->dados = al;

        no->ant->prox = novo;
        novo->ant = no->ant;

        no->ant = novo;
        novo->prox = no;
    }

    return 0;
}

int remove_lista_final_teste(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elem *no = *li;
    printf("\nNO CRIADO:            %d", no);
    printf("\nNO->PROX:             %d", no->prox);
    printf("\nNO->ANT:              %d", no->ant);
    printf("\nNO->PROX->PROX:       %d", no->prox->prox);
    printf("\nNO->PROX->PROX->PROX: %d\n-----\n", no->prox->prox->prox);
    int i = 1;
    while(no->prox != NULL && i < 6) {
        no = no->prox;
        printf("\nNO%d: %d", i, no);
        printf("\nNO->PROX%d: %d", i, no->prox);
        printf("\nNO->ANT%d: %d\n", i, no->ant);
        i++;
    }
        printf("\nNO:             %d", no);
        printf("\nNO->ANT:        %d", no->ant);
        printf("\nNO->PROX:       %d", no->prox);
        printf("\nNO->PROX->PROX: %d", no->prox->prox);
        printf("\nNO->PROX->PROX: %d", no->prox->prox->prox);

    if(no->ant == NULL) {//remover o primeiro e único
        *li = no->prox;
        printf("\nno if\n");
    } else {
        //no->ant->prox = NULL;
        printf("\n------\nno->ant->prox: %d", no->ant->prox);
        printf("\nno->prox->prox: %d", no->prox->prox);
        no->ant->prox = no->prox;
;
        no->prox->ant = no->ant;
        printf("\n---\nno else\n---\n");
    }
    printf("\n===\nNO pra deletar: %d\n===\n", no);
    free(no);
    printf("\n===\nNO deletado: %d\n===\n", no);
    return 1;
}
int remove_lista_final_ttt(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elem *no2 = *li;
    int i = 1;
    while(no2->prox != NULL && i < 2)
        no2 = no2->prox;
        i++;
        printf("\nNO===%d: %d\n", i, no2);

    if(no2->ant == NULL) {//remover o primeiro e único
        *li = no2->prox;
        printf("\n-222-no if\n");
    }else{
        no2->ant->prox = NULL;
        printf("\n--222-\nno else\n---\n");
    }
    printf("\n===\nNO pra deletar: %d\n===\n", no2);
    free(no2);
    printf("\n===\nNO deletado: %d\n===\n", no2);
    return 1;
}
