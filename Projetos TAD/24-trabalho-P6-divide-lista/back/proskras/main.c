#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"
Lista* unirFilas(Lista* li1, int a) {
    Lista* li_temp = cria_lista();
    Lista* li_nova = cria_lista();
    struct aluno aluno_insere;
    int tes = 0;

    while (!lista_vazia(li1)) {
        ++tes;

        if (tes <= a) {
            consulta_lista_pos(li1, 1, &aluno_insere);
            insere_lista_final(li_temp, aluno_insere);
            remove_lista_inicio(li1);
        } else {
            consulta_lista_pos(li1, 1, &aluno_insere);
            insere_lista_final(li_nova, aluno_insere);
            remove_lista_inicio(li1);
        }
    }

    while (!lista_vazia(li_temp)) {
        consulta_lista_pos(li_temp, 1, &aluno_insere);
        insere_lista_final(li1, aluno_insere);
        remove_lista_inicio(li_temp);
    }

	return li_nova;
}

int main(){
    struct aluno a[4] = {{2},{4},{1},{3}};

    int i, dividirLista = 2, tam;
    Lista* li1 = cria_lista();
    tam = tamanho_lista(li1);

    for(i=0; i < 4; i++) {
        insere_lista_final(li1, a[i]);
    }

    imprime_lista(li1);

    if (dividirLista > 1 && dividirLista < tamanho_lista(li1)) {
        printf("----------------------------------------------------------------------\n");
        printf(" ELEMENTOS DA NOVA LISTA\n\n");
        imprime_lista(unirFilas(li1, dividirLista));
        printf("----------------------------------------------------------------------\n");
        printf(" ELEMENTOS DA PRIMEIRA LISTA\n\n");
        imprime_lista(li1);
        printf("----------------------------------------------------------------------\n");
    } else {
        printf("Nao foi Possivel dividir a Lista!\n");
    }

    libera_lista(li1);
    libera_lista(unirFilas(li1, 2));
    return 0;
}

