#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Compara.h"
int main(){
    int i;

    struct aluno a[LETRAS] = {"A", "B", "B", "A"};
    Pilha* x = cria_Pilha();
    Pilha* y = cria_Pilha();
    Pilha* temp = cria_Pilha();
    Pilha* copia = cria_Pilha();

    for(i = 0; i < LETRAS; i++)
        insere_Pilha(x, a[i]);

    printf("Pilha X = \n");
    imprime_Pilha(x);
    printf("\n");

    for(i = LETRAS -1 ; i >= 0; i--)
        insere_Pilha(y , a[i]);

    printf("Pilha Y = \n");
    imprime_Pilha(y);

    remove_Pilha(x);

    struct aluno b[LETRAS] = {"P"};
    insere_Pilha(x , b[0]);
    printf("\nPilha X de novo alterada = \n");
    imprime_Pilha(x);
    printf("\n");

    compara_Pilha(x, y);

    inverte_Pilha(x, temp, copia);
    printf("\nPilha temp = \n");
    imprime_Pilha(temp);

    printf("Pilha copia = \n");
    imprime_Pilha(copia);

    libera_Pilha(x);
    libera_Pilha(y);
    libera_Pilha(temp);
    libera_Pilha(copia);
    return 0;
}
