#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"

int seqBemFormada(char* seq) {
	printf("Sequencia: %s\n\n", seq);

	Pilha* pi = cria_Pilha();

	for (int i = 0; i < seq[i] != '\0'; ++i) {
		struct item elemento;

		if ( (seq[i] == ')') || (seq[i] == ']') || (seq[i] == '}') )  {

			if (Pilha_vazia (pi))
                return 0;
			consulta_topo_Pilha(pi, &elemento);
			remove_Pilha(pi);

			switch(seq[i]) {
				case ')': if (elemento.c != '(') return 0; break;
				case ']': if (elemento.c != '[') return 0; break;
				case '}': if (elemento.c != '{') return 0; break;
            }

		}else{
			elemento.c = seq[i];
			insere_Pilha(pi,elemento);
		}
	}

	int retorno = Pilha_vazia(pi);
	libera_Pilha(pi);
	return retorno;
}

int main(){

	char seq[20] = "([({})])";
	//char seq[20] = "{{()}([([()])])}";

	if (seqBemFormada(seq))
		printf("A sequencia E ;) bem formada.");
	else
		printf("A sequencia NAO E :( bem formada.");

	printf("\n\n");

    return 0;
}
