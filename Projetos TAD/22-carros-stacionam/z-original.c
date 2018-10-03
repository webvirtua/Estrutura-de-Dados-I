#include <stdio.h>
#include <stdlib.h>
#include "FilaEstatica.h"

#define MAX_ESTACIONAMENTO 6

void imprime_linha() {
	printf("------------------------------------------\n");
}

/*int existe_no_estacionamento(Fila* fi, struct carro al) {

   }*/

void remove_Estacionamento(Fila* fi, struct carro al) {
	int i;
	imprime_linha();
	if(fi == NULL)
		return ;
	remove_Fila(fi);
	al.qtde = al.qtde + 1;
	printf("Carro saiu: %s\n", al.placa);
	imprime_Fila(fi);
	return ;
}

void insere_Estacionamento(Fila* fi, struct carro al) {
	int i;
	imprime_linha();
	if(fi == NULL)
		return ;
	if(tamanho_Fila(fi) == MAX_ESTACIONAMENTO){
		printf("Tentou inserir: %s\n", al.placa);
		printf("\nNAO EXISTE VAGA\n");
		imprime_linha();
	return ;
	}
	insere_Fila(fi, al);
	printf("Carro chegando: %s\n", al.placa);
	imprime_Fila(fi);
	return ;


}

int main(){
    struct carro a[10] = {{"AAA0000",0},
						 {"BBB1111",0},
                         {"CCC2222",0},
                         {"DDD3333",0},
                         {"EEE4444",0},
						 {"FFF5555",0},
						 {"GGG6666",0},
						 {"HHH7777",0},
						 {"III8888",0},
						 {"JJJ9999",0}
						 };

	Fila* fi = cria_Fila();
    int i;

    printf("\nSAIDA ESPERADA: ITEM (A)\n");
    imprime_linha();
    for( i=0; i < MAX_ESTACIONAMENTO; i++){
        insere_Estacionamento(fi, a[i]);
    }
    insere_Estacionamento(fi, a[6]);


	/*
    printf("\nSAIDA ESPERADA: ITEM (B)\n");
    imprime_linha();

	printf("O carro %s", a[3]);
    if (existe_no_estacionamento(fi, a[3])) {
    	printf(" ESTA no estacionameto.\n");
	} else {
		printf(" NAO esta no estacionameto.\n");
	}
	imprime_linha();

	printf("O carro %s", a[8]);
    if (existe_no_estacionamento(fi, a[8])) {
    	printf(" ESTA no estacionameto.\n");
	} else {
		printf(" NAO esta no estacionameto.\n");
	}
	imprime_linha();
    */


	printf("\nSAIDA ESPERADA: ITEM (C)\n");
    remove_Estacionamento(fi, a[2]);
	insere_Estacionamento(fi, a[6]);
	remove_Estacionamento(fi, a[4]);
    remove_Estacionamento(fi, a[9]);
    insere_Estacionamento(fi, a[9]);
    remove_Estacionamento(fi, a[6]);


    libera_Fila(fi);

    return 0;
}

