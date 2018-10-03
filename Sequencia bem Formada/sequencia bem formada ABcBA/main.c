#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"

int seqBemFormada(char* X) {
    int count, mod, retorno;
    struct item pega[20] = {"A"};
    struct item elemento;

    printf("Sequencia: %s\n\n", X);

    for (int i = 0; i < X[i] != '\0'; ++i) {
        count += 1;
    }

    mod = count % 2;

    if(mod == 0){
        return 0;
    }

	Pilha* M = cria_Pilha();
	Pilha* W = cria_Pilha();

	for (int i = 0; i < ((count - 1) / 2); ++i) {
        elemento.c = X[i];
        insere_Pilha(M, elemento);
	}

	for (int i = ((count - 1) / 2) + 1; i < count; ++i) {
        elemento.c = X[i];
        insere_Pilha(W, elemento);
	}

	invert_Pilha(W, tamanho_Pilha(W));

	retorno = Pilha_vazia(M);

	retorno = verifica_Formacao(M, W);

	libera_Pilha(M);
	libera_Pilha(W);
	return retorno;
}

int main(){

	char X[20] = "AABcBAA";
	//char X[20] = "AABBcBAB";
	//char X[20] = "ABab";

	if (seqBemFormada(X))
		printf("X pertence ao nosso Conjunto e tem a forma WcM.");
	else
		printf("X NAO pertence ao nosso Conjunto e não tem a forma WcM.");

	printf("\n\n");

    return 0;
}
