#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"
int contaCelulas(Lista* li1) {
    int count = 0;
    Lista* li_temp = cria_lista();
    struct aluno aluno_insere;

    while (!lista_vazia(li1)) {
        consulta_lista_pos(li1, 1, &aluno_insere);
        insere_lista_final(li_temp, aluno_insere);
        remove_lista_inicio(li1);
        count += 1;
    }

    while (!lista_vazia(li_temp)) {
        consulta_lista_pos(li_temp, 1, &aluno_insere);
        insere_lista_final(li1, aluno_insere);
        remove_lista_inicio(li_temp);
    }

    libera_lista(li_temp);
	return count;
}

int contaCelulasRecursiva(Lista* li1, int quant){
    struct aluno aluno_insere;

    while (quant > 0) {
        consulta_lista_pos(li1, quant, &aluno_insere);
        return (1 + contaCelulasRecursiva(li1, quant - 1));
    }

    return 0;
}

int main(){
    struct aluno a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}
                        };

    Lista* li1 = cria_lista();

    int i, tam;
    for(i=0; i < 4; i++) {
        insere_lista_ordenada(li1, a[i]);
    }

    printf("Quantidade de Celulas da Lista não Recursiva: %d\n\n", contaCelulas(li1));

    tam = tamanho_lista(li1);
    printf("Quantidade de Celulas da Lista Recursiva: %d\n\n", contaCelulasRecursiva(li1, tam));

    imprime_lista(li1);

    libera_lista(li1);
    return 0;
}
