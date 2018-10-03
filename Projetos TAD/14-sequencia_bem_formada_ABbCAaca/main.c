#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"

int seqBemFormada(char* seq) {
    int count, mod, retorno;
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

	for (int i = 0; i < count; ++i) {
        if(seq[i] > 96){
            if( (elemento.c - seq[i]) != 32)
            elemento.c = seq[i];
            insere_Pilha(pi2, elemento);

            Elem* no1 = *pi1;
            Elem* no2 = *pi2;

            int t1 = no1->dados.c;
            int t2 = no2->dados.c;

            if( (t2 - t1) != 32){
                return 0;
            }
            remove_Pilha(pi1);
            remove_Pilha(pi2);

        }else{
            elemento.c = seq[i];
            insere_Pilha(pi1, elemento);
        }
	}

	retorno = Pilha_vazia(pi1);

	libera_Pilha(pi1);
	libera_Pilha(pi2);
	return retorno;
}

int main(){

	char seq[20] = "ABCPZzpcBbWwba"; //sequencia bem formada
	//char seq[20] = "ABCPZzcpBbWwba"; //sequencia não e bem formada
	//char seq[20] = "WZABACCIFficcabazw"; //sequencia bem formada

	if (seqBemFormada(seq))
		printf("A sequencia E ;) bem formada.");
	else
		printf("A sequencia NAO E :( bem formada.");

	printf("\n\n");

    return 0;
}












