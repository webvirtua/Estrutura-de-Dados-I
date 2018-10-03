#include <stdio.h>
#include <stdlib.h>
#include "FilaEstatica.h"
void unirFilas(Fila* fi1, Fila* fi2){
    int i;
    int c1 = tamanho_Fila(fi1);
    int c2 = tamanho_Fila(fi2);
    int cc = c1 + c2;
    int vet[c1];

    Fila* fi_temp = cria_Fila();
    struct aluno al_temp;

    for (i = 0; i < c1; i++){
        consulta_Fila(fi1, &al_temp);
        vet[i] = al_temp.matricula;
        insere_Fila(fi_temp, al_temp);
        remove_Fila(fi1);
    }

    for (i = 0; i < c2; i++){
        consulta_Fila(fi2, &al_temp);

        if (al_temp.matricula == vet[i]){
            remove_Fila(fi2);
            cc--;
        } else {
            insere_Fila(fi_temp, al_temp);
            remove_Fila(fi2);
        }
    }

    for (i = 0; i < cc; i++){
        consulta_Fila(fi_temp, &al_temp);
        insere_Fila(fi1, al_temp);
        remove_Fila(fi_temp);
    }

    imprime_Fila(fi_temp);
    libera_Fila(fi_temp);
}

int main(){
    int i;

    struct aluno al, a[4] = {
                               {10,"Andre",9.5,7.8,8.5},
                               {20,"Ricardo",7.5,8.7,6.8},
                               {30,"Bianca",9.7,6.7,8.4},
                               {40,"Ana",5.7,6.1,7.4}
                            };
    struct aluno ab, b[4] = {
                               {10,"Andre",9.5,7.8,8.5},
                               {60,"Mane",6.5,7.7,8.8},
                               {70,"Joao",9.7,6.7,8.4},
                               {80,"Keno",9.7,1.1,2.4}
                           };

    Fila* fi1 = cria_Fila();
    Fila* fi2 = cria_Fila();

    for(i = 0; i < 4; i++){
        insere_Fila(fi1, a[i]);
        if(Fila_vazia(fi1))
            printf("Erro!!!!!!\n");
    }

    for(i = 0; i < 4; i++){
        insere_Fila(fi2, b[i]);
        if(Fila_vazia(fi2))
            printf("Erro!!!!!!\n");
    }

    unirFilas(fi1, fi2);

    imprime_Fila(fi1);
    imprime_Fila(fi2);

    libera_Fila(fi1);
    libera_Fila(fi2);

    return 0;
}

