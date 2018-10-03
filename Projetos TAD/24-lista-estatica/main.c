#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"
void unirFilas(Lista* li, struct aluno al) {
    insere_lista_final(li, al);
	return ;
}

int main(){
    struct aluno a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}
                        };

    Lista* li1 = cria_lista();
    Lista* li2 = cria_lista();
    struct aluno aluno_insere;

    int i;
    for(i=0; i < 4; i++) {
        insere_lista_ordenada(li1, a[i]);
    }

    for(i=0; i < 4; i++) {
        insere_lista_final(li2, a[i]);
    }

    imprime_lista(li1);
    imprime_lista(li2);
    printf("\n\n\n\n");

    libera_lista(li1);
    libera_lista(li2);
    return 0;
}

