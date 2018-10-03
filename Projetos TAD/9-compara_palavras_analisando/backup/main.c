#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Compara.h"
int main(){
    struct aluno a[LETRAS] = {"A", "B", "B", "A"};
    Pilha* x = cria_Pilha();
    Pilha* y = cria_Pilha();
    Pilha* temp = cria_Pilha();
    Pilha* copia = cria_Pilha();
    int i;

    for(i = 0; i < LETRAS; i++)
        insere_Pilha(x, a[i]);

    printf("Pilha X = ");
    imprime_Pilha(x);
    printf("\n");

    for(i = LETRAS -1 ; i >= 0; i--)
        insere_Pilha(y , a[i]);

    printf("Pilha Y = ");
    imprime_Pilha(y);

    //remove_Pilha(x);
    //insere_Pilha(x, a[1]);
    printf("\nPilha X de novo = ");
    imprime_Pilha(x);
    printf("\n");

    compara_Pilha(x, y);

    inverte_Pilha(x, temp, copia);
    printf("Pilha copia = ");
    imprime_Pilha(copia);

    libera_Pilha(x);
    libera_Pilha(y);
    return 0;
}
