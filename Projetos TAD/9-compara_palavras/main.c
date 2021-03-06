#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Compara.h"

int main(){
    struct aluno a[LETRAS] = {{"A"}, {"B"}, {"C"}, {"D"}};
    Pilha* x = cria_Pilha();
    Pilha* y = cria_Pilha();
    Pilha* z = cria_Pilha();
    int i;

    for(i = 0; i < LETRAS; i++)
        insere_Pilha(z, a[i]);

    for(i = 0; i < LETRAS; i++)
        insere_Pilha(x, a[i]);

    printf("Pilha X = ");
    imprime_Pilha(x);
    printf("\n");

    for(i = LETRAS -1 ; i >= 0; i--)
        insere_Pilha(y , a[i]);

    printf("Pilha Y = ");
    imprime_Pilha(y);
    compara_Pilha(x, y);

    transfere_Pilha(x, z);

    consulta_topo_Pilha(x, y);

    libera_Pilha(x);
    libera_Pilha(y);
    return 0;
}
