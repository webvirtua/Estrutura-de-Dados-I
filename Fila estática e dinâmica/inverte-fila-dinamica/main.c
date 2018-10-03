#include <stdio.h>
#include <stdlib.h>
#include "UnirFilas.h"
void invertFila(Fila* fi1){
    int i;
    int c1 = tamanho_Fila(fi1);
    int cc = tamanho_Fila(fi1);

    Fila* fi_temp = cria_Fila();
    Fila* fi_temp2 = cria_Fila();
    Fila* fi_temp3 = cria_Fila();
    struct aluno al_temp;

    for (i = 1; i <= c1; i++){
        consulta_Fila(fi1, &al_temp);
        insere_Fila(fi_temp, al_temp);
        remove_Fila(fi1);
    }

    for (i = 1; i <= cc; i++){
        consulta_Fila(fi_temp, &al_temp);

        if(cc != i){
            insere_Fila(fi_temp2, al_temp);
        }
        remove_Fila(fi_temp);

        if(cc == i){
            consulta_Fila(fi_temp, &al_temp);
            insere_Fila(fi_temp3, al_temp);
            remove_Fila(fi_temp);
            cc = --cc;
            i = 1;

            for (i = 1; i <= cc; i++){
                consulta_Fila(fi_temp2, &al_temp);
                insere_Fila(fi_temp, al_temp);
                remove_Fila(fi_temp2);
            }
            i = 0;
        }
    }

    for (i = 1; i <= c1; i++){
        consulta_Fila(fi_temp3, &al_temp);
        insere_Fila(fi1, al_temp);
        remove_Fila(fi_temp3);
    }

    imprime_Fila(fi_temp);
    imprime_Fila(fi_temp2);
    imprime_Fila(fi_temp3);

    libera_Fila(fi_temp);
    libera_Fila(fi_temp2);
    libera_Fila(fi_temp3);
}

int main(){
    int i;

    struct aluno al, a[4] = {
                               {10,"Andre",9.5,7.8,8.5},
                               {20,"Ricardo",7.5,8.7,6.8},
                               {30,"Bianca",9.7,6.7,8.4},
                               {40,"Ana",5.7,6.1,7.4}
                            };

    Fila* fi1 = cria_Fila();

    for(i = 0; i < 4; i++){
        insere_Fila(fi1, a[i]);
        if(Fila_vazia(fi1))
            printf("Erro!!!!!!\n");
    }

    invertFila(fi1);

    imprime_Fila(fi1);

    libera_Fila(fi1);

    return 0;
}
