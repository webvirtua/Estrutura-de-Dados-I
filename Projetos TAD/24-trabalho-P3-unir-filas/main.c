#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"
Lista* unirFilas(Lista* li1, Lista* li2) {
    Lista* li_temp = cria_lista();
    struct aluno aluno_insere;

    while (!lista_vazia(li1)) {
        consulta_lista_pos(li1, 1, &aluno_insere);
        insere_lista_final(li_temp, aluno_insere);
        remove_lista_inicio(li1);
    }

    while (!lista_vazia(li2)) {
        consulta_lista_pos(li2, 1, &aluno_insere);
        insere_lista_final(li_temp, aluno_insere);
        remove_lista_inicio(li2);
    }

	return li_temp;
}

int main(){
    struct aluno a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}
                        };

    Lista* li1 = cria_lista();
    Lista* li2 = cria_lista();

    int i;
    for(i=0; i < 4; i++) {
        insere_lista_ordenada(li1, a[i]);
    }

    for(i=0; i < 4; i++) {
        insere_lista_final(li2, a[i]);
    }

    imprime_lista(unirFilas(li1, li2));

    libera_lista(li1);
    libera_lista(li2);
    return 0;
}

