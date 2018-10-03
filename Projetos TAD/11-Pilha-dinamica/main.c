#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"
//cada elemento aponta para o sucessor na pilha, sem vetor
int main(){
    int i;

    struct aluno a[4] = {{10,"Andre",9.5,7.8,8.5},
                         {20,"Ricardo",7.5,8.7,6.8},
                         {30,"Bianca",9.7,6.7,8.4},
                         {40,"Ana",5.7,6.1,7.4}};

    Pilha* pi = cria_Pilha();

    printf("Tamanho 1: %d\n\n\n\n",tamanho_Pilha(pi));

    for(i = 0; i < 4; i++)
        insere_Pilha(pi, a[i]);

    consulta_topo_Pilha(pi);
    imprime_Pilha(pi);

    printf("\nTamanho 2: %d\n\n",tamanho_Pilha(pi));

    printf("Removendo todos os registros: \n");
    for(i = 0; i < 4; i++)
        remove_Pilha(pi);

    printf("Tamanho 3: %d\n\n",tamanho_Pilha(pi));

    printf("Imprimindo pilha apos remover: \n\n");
    imprime_Pilha(pi);

    printf("Removendo pilha vazia: \n\n");
    remove_Pilha(pi);

    printf("Inserindo todos os registros novamente: \n");
    for(i = 0; i < 4; i++)
        insere_Pilha(pi,a[i]);

    //remove_Pilha(pi);
    struct aluno b[4] = {{100,"Luiz Rodrigues",9.5,8.8,9.9}};
    insere_Pilha(pi,b[0]);

    printf("Tamanho 4: %d\n\n",tamanho_Pilha(pi));
    imprime_Pilha(pi);

    libera_Pilha(pi);
    return 0;
}
