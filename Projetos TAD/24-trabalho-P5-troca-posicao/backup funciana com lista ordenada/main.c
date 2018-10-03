#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"
int invertElementos(Lista* li1, int a, int b) {
    Lista* li_temp = cria_lista();
    Lista* li_inve = cria_lista();
    struct aluno aluno_insere;
    int item1 = a, item2 = b, mat, temp, itemFix1, itemFix2;
    float menor;

    if (a > b) {
        item1 = b;
        item2 = a;
    }
    itemFix1 = item1, itemFix2 = item2;

    if (a == b) {
        return 0;
    }

    consulta_lista_pos(li1, item1, &aluno_insere);
    insere_lista_final(li_temp, aluno_insere);
    mat = aluno_insere.matricula;

    consulta_lista_pos(li1, item2, &aluno_insere);
    insere_lista_final(li_temp, aluno_insere);
    mat = aluno_insere.matricula;
    printf("------li1----------------------------------------------------------------\n");
    imprime_lista(li1);
    printf("-------li_temp---------------------------------------------------------------\n");
    imprime_lista(li_temp);
    printf("----------------------------------------------------------------------\n");


    while (!lista_vazia(li1)) {
        consulta_lista_pos(li1, 1, &aluno_insere);

        if (aluno_insere.matricula == item1){
            remove_lista_inicio(li1);
            while (!lista_vazia(li1)) {
                consulta_lista_pos(li1, 1, &aluno_insere);
                if (aluno_insere.matricula == item2){
                    remove_lista_inicio(li1);
                } else {
                    insere_lista_final(li_inve, aluno_insere);
                    remove_lista_inicio(li1);
                }
            }
            item1 = 0;
        }

        if (!lista_vazia(li1)) {
            insere_lista_final(li_inve, aluno_insere);
            remove_lista_inicio(li1);
        }
    }

    for (int i = 0; i < 4; i++) {
        int tes = i +1;

        if (tes == itemFix1) {
            consulta_lista_pos(li_temp, 2, &aluno_insere);
            insere_lista_final(li1, aluno_insere);
            remove_lista_final(li_temp);
        } else if (tes == itemFix2) {
            consulta_lista_pos(li_temp, 1, &aluno_insere);
            insere_lista_final(li1, aluno_insere);
            remove_lista_inicio(li_temp);
        } else {
            consulta_lista_pos(li_inve, 1, &aluno_insere);
            insere_lista_final(li1, aluno_insere);
            remove_lista_inicio(li_inve);
        }
    }

	return 1;
}

int main(){
    struct aluno a[4] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4}
                        };

    Lista* li1 = cria_lista();

    int i;
    for(i=0; i < 4; i++) {
        insere_lista_ordenada(li1, a[i]);
    }

    //imprime_lista(li1);

    printf("----------------------------------------------------------------------\n");
    if (invertElementos(li1, 3, 1)) {
        printf("Operacao de inverter os elementos foi realizada com sucesso!\n");
    } else {
        printf("Operacao de inverter os elementos nao foi Possivel!\n");
    }
    printf("----------------------------------------------------------------------\n");

    imprime_lista(li1);

    libera_lista(li1);
    return 0;
}

