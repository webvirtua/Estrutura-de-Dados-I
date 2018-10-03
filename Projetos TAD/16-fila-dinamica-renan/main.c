#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h"
int main(){
    int i;

    struct aluno al,a[4] = {
                               {10,"Andre",9.5,7.8,8.5},
                               {20,"Ricardo",7.5,8.7,6.8},
                               {30,"Bianca",9.7,6.7,8.4},
                               {40,"Ana",5.7,6.1,7.4}
                           };

    Fila* fi = cria_Fila();
    printf("Tamanho: %d\n\n\n\n", tamanho_Fila(fi));

    for(i = 0; i < 4; i++){
        insere_Fila(fi, a[i]);
        if(Fila_vazia(fi))
            printf("Erro!!!!!!\n");
        consulta_Fila(fi, &al);
        printf("Consulta: %d \t %s\n", al.matricula, al.nome);
    }
    printf("--------------------------------------\n\n");

    remove_Fila(fi);
    remove_Fila(fi);
    remove_Fila(fi);
    insere_Fila(fi, a[0]);
    imprime_Fila(fi);

    printf("Tamanho: %d\n\n\n\n", tamanho_Fila(fi));

    for(i = 0; i < 4; i++){
        remove_Fila(fi);
        consulta_Fila(fi, &al);
        printf("Consulta: %d \t %s\n", al.matricula, al.nome);
    }
    printf("--------------------------------------\n\n");

    printf("Tamanho: %d\n\n\n\n", tamanho_Fila(fi));
    imprime_Fila(fi);

    for(i = 0; i < 4; i++)
        insere_Fila(fi, a[i]);

    printf("Tamanho: %d\n\n\n\n",tamanho_Fila(fi));
    imprime_Fila(fi);

    libera_Fila(fi);

    return 0;
}

