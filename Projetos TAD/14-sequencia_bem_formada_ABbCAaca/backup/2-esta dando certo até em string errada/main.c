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
    printf("Quantidade de caracteres: %i\n\n", count);

    mod = count % 2;

    if(mod == 1){
        return 0;
    }

	Pilha* pi1 = cria_Pilha();
	Pilha* pi2 = cria_Pilha();
	printf("seq[0]=>: %i\n\n", seq[0]);
	printf("seq[5]=>: %i\n\n", seq[5]);

	for (int i = 0; i < count; ++i) {
        if(seq[i] < 97){
            elemento.c = seq[i];
            insere_Pilha(pi1, elemento);
        }

        for (int j = (count / 2); j < count; ++j) {
            if(seq[j] - seq[i] == 32){
                elemento.c = seq[j];
                insere_Pilha(pi2, elemento);
                printf("no if---\n\n");
            }
        }
	}


	imprime_Pilha(pi1);
	printf("---------------------------------");
	imprime_Pilha(pi2);

	retorno = Pilha_vazia(pi1);

	retorno = verifica_Formacao(pi1, pi2);

	libera_Pilha(pi1);
	return retorno;
}

int main(){

	char seq[20] = "ABab";

	if (seqBemFormada(seq))
		printf("A sequencia E ;) bem formada.");
	else
		printf("A sequencia NAO E :( bem formada.");

	printf("\n\n");

    return 0;
}
/*WZABACCIFficcabazw
Ww
ZABACCIFficcabaz
Zz
ABACCIFficcaba
Aa
BACCIFficcba
Bb
ACCIFficca
Aa
CCIFficc
Cc
CIFfic
Cc
IFfi
Ii
-
Ff
--
0*/












