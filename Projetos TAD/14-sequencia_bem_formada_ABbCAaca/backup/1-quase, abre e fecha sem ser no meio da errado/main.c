#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"

int seqBemFormada(char* seq) {
    int count, mod, retorno;
    struct item pega[20] = {"A"};
    struct item elemento;

    printf("Sequencia: %s\n\n", seq);

    for (int i = 0; i < seq[i] != '\0'; ++i) {
        count += 1;
    }

    mod = count % 2;

    if(mod == 1){
        return 0;
    }

	Pilha* pi1 = cria_Pilha();
	Pilha* pi2 = cria_Pilha();

	for (int i = 0; i < (count / 2); ++i) {
        elemento.c = seq[i];
        insere_Pilha(pi1, elemento);
	}

	for (int i = (count / 2); i < count; ++i) {
        elemento.c = seq[i];
        insere_Pilha(pi2, elemento);
	}

	invert_Pilha(pi2, tamanho_Pilha(pi2));

	retorno = Pilha_vazia(pi1);

	retorno = verifica_Formacao(pi1, pi2);

	libera_Pilha(pi1);
	return retorno;
}

int main(){

	char seq[20] = "WZBbABCIFficbazw";

	if (seqBemFormada(seq))
		printf("A sequencia E ;) bem formada.");
	else
		printf("A sequencia NAO E :( bem formada.");

	printf("\n\n");

    return 0;
}
