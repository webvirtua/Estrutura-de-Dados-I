#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UnirFilas.h" //inclui os Protótipos

Fila* cria_Fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
        fi->qtd = 0;
    }
    return fi;
}

void libera_Fila(Fila* fi){
    if(fi != NULL){
        Elem* no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int consulta_Fila(Fila* fi, struct aluno *al){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    *al = fi->inicio->dados;
    return 1;
}

int insere_Fila(Fila* fi, struct aluno al){
    if(fi == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if(fi->final == NULL)//fila vazia
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    fi->qtd++;
    return 1;
}

int remove_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL)//fila ficou vazia
        fi->final = NULL;
    free(no);
    fi->qtd--;
    return 1;
}

int tamanho_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    return fi->qtd;
}

int Fila_vazia(Fila* fi){
    if(fi == NULL)
        return 1;
    if(fi->inicio == NULL)
        return 1;
    return 0;
}

int Fila_cheia(Fila* fi){
    return 0;
}

void imprime_Fila(Fila* fi){
    if(fi == NULL)
        return;
    Elem* no = fi->inicio;
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

void unirFilas(Fila* fi1, Fila* fi2){
    printf("Tamanho fila a =>: %d\n", tamanho_Fila(fi1));
    printf("Tamanho fila b =>: %d\n", tamanho_Fila(fi2));
    int mat, i = 0;
    char nome[30];

    Fila* fi_aux = cria_Fila();
    struct aluno al_aux;

    //struct aluno ac, c[4];


    if(fi1 == NULL)
        return;
    Elem* no = fi1->inicio;
    while(no != NULL){
        printf("Matricula: %d\n", mat = no->dados.matricula);
        printf("Nome: %s\n", no->dados.nome);
        stpcpy(nome, no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");
        no = no->prox;

        //insere_Fila(fi1, no->dados[0]);
        //fi2->dados[i] = al;
        //i++;
    }

   // struct aluno ac, c[4] = {{mat,"zzzz",3.5,4.8,5.5}};
                          // insere_Fila(fi2, c[0]);

    if(fi2 == NULL)
        return;
    Elem* no2 = fi2->inicio;
    while(no2 != NULL){
        printf("Matricula: %d\n",no2->dados.matricula);
        printf("Nome: %s\n",no2->dados.nome);
        printf("Notas: %f %f %f\n",no2->dados.n1,
                                   no2->dados.n2,
                                   no2->dados.n3);
        printf("-------------------------------\n");
        no2 = no2->prox;

        //insere_Fila(fi1, no->dados[0]);
    }

    printf("--------------------------------------------------------------------------\n");
        for (i = 0; i < 4; i++){
            if (consulta_Fila(fi1, &al_aux)){
              insere_Fila(fi_aux, al_aux);
              remove_Fila(fi1);
            }
        }

        imprime_Fila(fi_aux);

    printf("----------------------------------====----------------------------------------\n");

    for (i = 0; i < 4; i++){
            consulta_Fila(fi_aux, &al_aux);
              insere_Fila(fi1, al_aux);
              //remove_Fila(fi_aux);
            printf("==>\n");
        }

        struct aluno ab, b[4] = {
                               {50,"Ze",3.5,4.8,5.5},
                               {60,"Mane",6.5,7.7,8.8},
                               {70,"Joao",9.7,6.7,8.4},
                               {80,"Keno",9.7,1.1,2.4}
                           };

                           insere_Fila(fi1, b[0]);

        imprime_Fila(fi1);
}
