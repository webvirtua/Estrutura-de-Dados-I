#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Compara.h"
int main(){
    struct aluno a[LETRAS] = {{"A"}, {"B"}, {"B"}, {"A"}};
    Pilha* x = cria_Pilha();
    Pilha* y = cria_Pilha();
    int i;

    for(i = 0; i < LETRAS; i++)
        insere_Pilha(x, a[i]);

    printf("Pilha X = ");
    imprime_Pilha(x);
    printf("\n");

    for(i = LETRAS -1 ; i >= 0; i--)
        inverte_Pilha(y , a[i]);

    printf("Pilha Y = ");
    imprime_Pilha(y);
    compara_Pilha(x, y);

    printf("\n\nTamanho da pilha X = %i",tamanho_Pilha(x));
    printf("\nTamanho da pilha Y = %i",tamanho_Pilha(y));
    printf("\n\n");

    libera_Pilha(x);
    libera_Pilha(y);
    return 0;
}
