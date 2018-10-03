#include <stdio.h>
#include <stdlib.h>
#include "PilhaSequencial.h" //inclui os Protótipos

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

int consulta_topo_Pilha(Pilha* pi, struct aluno *al){
    if(pi == NULL || pi->qtd == 0)
        return 0;
    *al = pi->dados[pi->qtd-1];
    return 1;
}

int insere_Pilha(Pilha* pi, struct aluno al){
    if(pi == NULL)
        return 0;
    if(pi->qtd == MAX)//pilha cheia
        return 0;
    pi->dados[pi->qtd] = al;
    pi->qtd++;
    return 1;
}

int remove_Pilha(Pilha* pi){
    if(pi == NULL || pi->qtd == 0)
        return 0;
    pi->qtd--;
    return 1;
}

int tamanho_Pilha(Pilha* pi){
    if(pi == NULL)
        return -1;
    else
        return pi->qtd;
}

int Pilha_cheia(Pilha* pi){
    if(pi == NULL)
        return -1;
    return (pi->qtd == MAX);
}

int Pilha_vazia(Pilha* pi){
    if(pi == NULL)
        return -1;
    return (pi->qtd == 0);
}

void imprime_Pilha(Pilha* pi){
    if(pi == NULL)
        return;
    int i;
    for(i=pi->qtd-1; i >=0; i--){
        printf("Matricula: %d\n",pi->dados[i].matricula);
        printf("Nome: %s\n",pi->dados[i].nome);
        printf("Notas: %f %f %f\n",pi->dados[i].n1,
                                   pi->dados[i].n2,
                                   pi->dados[i].n3);
        printf("-------------------------------\n");
    }
}

void escolheNaPilha(Pilha* pi){
    if(pi == NULL)
        return;

    printf("Pilha %i\n", pi->qtd);
    printf("Aluno %i e %s\n", pi->qtd, pi->dados[pi->qtd - 1].nome);
    printf("Acessa Nome: %s\n",pi->dados[pi->qtd - 1].nome);

    int num;
    printf("NUMERO DO ALUNO QUE DESEJA NA PILHA: ");
    scanf("%i", &num);

    if(num > pi->qtd - 1){
        printf("Nao existe esse numero na pilha");
    }else{
        for(int i = pi->qtd; i >= num; i--){
            num = num--;
            printf("%i num no for %i\n", i, num);

        printf("-------------------------------\n");
        }

        printf("Acessa Matricula: %d\n",pi->dados[num - 1].matricula);
        printf("\nAcessa Nome: %s\n",pi->dados[num - 1].nome);
        printf("Acessa Notas: %f %f %f\n",pi->dados[num - 1].n1,
                                          pi->dados[num - 1].n2,
                                          pi->dados[num - 1].n3);
    }
}
