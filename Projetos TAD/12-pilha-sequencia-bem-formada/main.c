#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"

int seqBemFormada(char* seq) {
	printf("Sequencia: %s\n\n", seq);

	Pilha* pi = cria_Pilha();

	printf("imprime pilha %c\n", seq[0]);
	printf("imprime pilha %i\n", seq[0]);
	printf("imprime pilha %c\n", seq[5]);
	printf("imprime pilha %i\n\n", seq[5]);
	imprime_Pilha(pi);

	for (int i = 0; i < seq[i] != '\0'; ++i) {
		struct item elemento;

		if (seq[i] > 96 && seq[i] < 123)  {
            printf("vendo no if %c\n", seq[i]);
            printf("vendo no if  %i\n", seq[i]);
            int temp = seq[i];

			if (Pilha_vazia (pi))
                return 0;
			consulta_topo_Pilha(pi, &elemento);
			remove_Pilha(pi);


			switch(seq[i]) {
				case 97: if (elemento.c != 'A') return 0; break;
				case 'b': if (elemento.c != 'B') return 0; break;
				case 'c': if (elemento.c != 'C') return 0; break;
            }

		}else{
			elemento.c = seq[i];
			insere_Pilha(pi,elemento);
			printf("no else %c\n\n", elemento);
		}
	}

	//imprime_Pilha(pi);

	int retorno = Pilha_vazia(pi);

	libera_Pilha(pi);
	return retorno;
}

int main(){

	char seq[20] = "ABCcbCcBab";
	//char seq[20] = "{{()}([([()])])}";

	if (seqBemFormada(seq))
		printf("A sequencia E ;) bem formada.");
	else
		printf("A sequencia NAO E :( bem formada.");

	printf("\n\n");

    return 0;
}
