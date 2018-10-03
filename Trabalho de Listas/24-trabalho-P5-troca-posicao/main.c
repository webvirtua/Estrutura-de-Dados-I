#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"
int invertElementos(Lista* li1, int a, int b) {
    Lista* li_temp = cria_lista();
    Lista* li_inve = cria_lista();
    struct aluno aluno_insere;
    int item1 = a, item2 = b, tes = 0;

    if (a == b) {
        return 0;
    } else if (a > b) {
        item1 = b;
        item2 = a;
    }

    consulta_lista_pos(li1, item1, &aluno_insere);
    insere_lista_inicio(li_temp, aluno_insere);

    consulta_lista_pos(li1, item2, &aluno_insere);
    insere_lista_inicio(li_temp, aluno_insere);

    while (!lista_vazia(li1)) {
        ++tes;

        if (tes == item1) {
            consulta_lista_pos(li_temp, 1, &aluno_insere);
            insere_lista_final(li_inve, aluno_insere);
            remove_lista_inicio(li_temp);
            remove_lista_inicio(li1);
        } else if (tes == item2) {
            consulta_lista_pos(li_temp, 1, &aluno_insere);
            insere_lista_final(li_inve, aluno_insere);
            remove_lista_final(li_temp);
            remove_lista_inicio(li1);
        } else {
            consulta_lista_pos(li1, 1, &aluno_insere);
            insere_lista_final(li_inve, aluno_insere);
            remove_lista_inicio(li1);
        }
    }

    while (!lista_vazia(li_inve)) {
        consulta_lista_pos(li_inve, 1, &aluno_insere);
        insere_lista_final(li1, aluno_insere);
        remove_lista_inicio(li_inve);
    }

    libera_lista(li_temp);
    libera_lista(li_inve);

	return 1;
}

int main(){
    struct aluno a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}
                        };

    int i, tam, pos1 = 4, pos2 = 1;
    Lista* li1 = cria_lista();

    for(i=0; i < 4; i++) {
        insere_lista_final(li1, a[i]);
    }
    tam = tamanho_lista(li1);

    imprime_lista(li1);

    printf("----------------------------------------------------------------------\n");
    if ( (pos1 < 1 || pos1 > tam) || (pos2 < 1 || pos2 > tam) ) {
        printf("Operacao de inverter os elementos nao foi Possivel!\n");
        printf("\nA lista tem %d posicoes, escolha da posição 1 ate %d\n", tam, tam);
    } else if (invertElementos(li1, pos1, pos2)) {
        printf("Operacao de inverter os elementos foi realizada com sucesso!\n");
    } else {
        printf("Operacao de inverter os elementos nao foi Possivel!\n");
    }
    printf("----------------------------------------------------------------------\n");

    imprime_lista(li1);

    libera_lista(li1);
    return 0;
}

