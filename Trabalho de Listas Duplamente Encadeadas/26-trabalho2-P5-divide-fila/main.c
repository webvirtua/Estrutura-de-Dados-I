#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncadDupla.h"
int main(){
    struct aluno al, a[5] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4},
                         {666,"Vai",10.5,10.8,10.5}};
    Lista* li1 = cria_lista();
    Lista* li2 = cria_lista();
    Lista* li3 = cria_lista();
    struct aluno aluno_insere;
    printf("Tamanho: %d\n\n\n\n",tamanho_lista(li1));

    int i;
    for(i=0; i < 4; i++)
        insere_lista_ordenada(li1,a[i]);


    printf("\n Tamanho: %d\n",tamanho_lista(li1));

    insere_pos(li1, a[4], 5);

    imprime_lista(li1);

    printf("\n****************************************\n");
    divide_lista(li1, li2, li3, 3);

    printf("\n*************NOVA LISTA 1***************\n");
    imprime_lista(li2);
    printf("\n*************NOVA LISTA 2***************\n");
    imprime_lista(li3);

    libera_lista(li1);
}

