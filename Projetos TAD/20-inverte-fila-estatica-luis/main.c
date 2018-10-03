#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

int main(){
    struct aluno al,a[4] = {{100,"Andre",9.5,7.8,8.5},
                         {200,"Ricardo",7.5,8.7,6.8},
                         {300,"Bianca",9.7,6.7,8.4},
                         {400,"Ana",5.7,6.1,7.4}};
    Fila* fi = cria_Fila();

    int i;



    for(i=0; i < 4; i++){
        insere_Fila(fi,a[i]);
        if(Fila_vazia(fi))
          printf("Erro!!!!!!\n");
    }



   imprime_Fila(fi);
   printf("\n\n\n");


   inverte_Fila(fi);
   imprime_Fila(fi);




    libera_Fila(fi);

    return 0;
}
