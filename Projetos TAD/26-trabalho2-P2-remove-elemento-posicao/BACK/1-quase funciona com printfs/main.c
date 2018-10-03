#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncadDupla.h"
int main(){
    struct aluno al, a[5] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4},
                         {666,"Vai",10.5,10.8,10.5}};
    Lista* li = cria_lista();
    struct aluno aluno_insere;
    printf("Tamanho: %d\n\n\n\n",tamanho_lista(li));

    int i;
    for(i=0; i < 4; i++)
        insere_lista_ordenada(li,a[i]);

    imprime_lista(li);
    printf("\n Tamanho: %d\n",tamanho_lista(li));

    insere_pos(li, a[4], 5);
    insere_pos(li, a[2], 6);
    insere_pos(li, a[0], 7);
    insere_pos(li, a[3], 8);

    printf("\n****************************************\n");
    remove_lista_final_teste(li);
    //remove_lista_final_ttt(li);

    imprime_lista(li);

    printf("\n*------depoisss---------------------------------*\n");

    //consulta_lista_pos(li, 2, &aluno_insere);
    //printf("Consulta: %d \t %s\n", al.matricula, al.nome);

    //remove_lista(li,3);
    /*for(i=0; i < 4; i++){
        remove_lista_final(li);
        imprime_lista(li);
        printf("\nTamanho: %d\n\n\n\n",tamanho_lista(li));
    }*/

    /*for(i=0; i < 4; i++)
        insere_lista_ordenada(li,a[i]);
    */
    //imprime_lista(li);
    libera_lista(li);
}

