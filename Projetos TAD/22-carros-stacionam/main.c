#include <stdio.h>
#include <stdlib.h>
#include "FilaEstatica.h"
#include <string.h>
#define MAX_ESTACIONAMENTO 6

void imprime_linha() {
	printf("------------------------------------------\n");
}

int existe_no_estacionamento(Fila* fi, struct carro al) {
	int i, count, existe = 0;
	struct carro alTemp;
	count = tamanho_Fila(fi);

	Fila* fiTemp = cria_Fila();

	for (i = 0; i < count; i++) {
		consulta_Fila(fi, &alTemp);
		insere_Fila(fiTemp, alTemp);
		remove_Fila(fi);

		if (strcmp(al.placa, alTemp.placa) == 0) {
			existe = 1;
		}
	}

	for (i = 0; i < count; i++) {
		consulta_Fila(fiTemp, &alTemp);
		insere_Fila(fi, alTemp);
		remove_Fila(fiTemp);
	}

	libera_Fila(fiTemp);
	return existe;
}

void remove_Estacionamento(Fila* fi, struct carro al) {
	int i, count, count2;
	struct carro alTemp;
	count = tamanho_Fila(fi);

	imprime_linha();
	if (existe_no_estacionamento(fi, al) == 1) {
		Fila* fiTemp = cria_Fila();

		for (i = 0; i < count; i++) {
			consulta_Fila(fi, &alTemp);
			alTemp.qtde++;
			if (strcmp(al.placa, alTemp.placa) == 0) {
				remove_Fila(fi);
				break;
			}
			insere_Fila(fiTemp, alTemp);
			remove_Fila(fi);
		}

		count2 = tamanho_Fila(fi);

		for (i = 0; i < count2; i++) {
			consulta_Fila(fi, &alTemp);
			insere_Fila(fiTemp, alTemp);
			remove_Fila(fi);
		}

		for (i = 0; i < count-1; i++) {
			consulta_Fila(fiTemp, &alTemp);
			insere_Fila(fi, alTemp);
			remove_Fila(fiTemp);
		}

		printf("O carro %s saiu\n", al.placa);
		imprime_Fila(fi);
		libera_Fila(fiTemp);
	} else {
        printf("O CARRO %s NAO FOI ENCONTRADO NO ESTACIONAMENTO!\n", al.placa);
    }

	imprime_linha();
}

void insere_Estacionamento(Fila* fi, struct carro al) {
    int i;

	imprime_linha();
	if(fi == NULL) {
		return;
    }

	if(tamanho_Fila(fi) == MAX_ESTACIONAMENTO){
		printf("Tentou inserir: %s\n", al.placa);
		printf("NAO EXISTE VAGA.\n");
		imprime_linha();
        return ;
	}

	insere_Fila(fi, al);
	printf("Carro chegando: %s\n", al.placa);
	imprime_Fila(fi);
	return ;
}

void mostraCarro(Fila* fi, struct carro al) {
    printf("O carro %s ", al.placa);
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

    printf("\nSAIDA ESPERADA: ITEM (A)\n");
    imprime_linha();

	int i;

    for(i=0; i < MAX_ESTACIONAMENTO; i++){
        insere_Estacionamento(fi, a[i]);
    }
    insere_Estacionamento(fi, a[6]);

    printf("\nSAIDA ESPERADA: ITEM (B)\n");
    imprime_linha();

	//printf("O carro %s", a[3]);
	mostraCarro(fi, a[3]);
    if (existe_no_estacionamento(fi, a[3])) {
    	printf(" ESTA no estacionameto.\n");
	} else {
		printf(" NAO esta no estacionameto.\n");
	}
	imprime_linha();

	//printf("O carro %s", a[8]);
	mostraCarro(fi, a[8]);
    if (existe_no_estacionamento(fi, a[8])) {
    	printf(" ESTA no estacionameto.\n");
	} else {
		printf(" NAO esta no estacionameto.\n");
	}
	imprime_linha();


	printf("\nSAIDA ESPERADA: ITEM (C)\n");
    remove_Estacionamento(fi, a[2]);
	insere_Estacionamento(fi, a[6]);
	remove_Estacionamento(fi, a[4]);
	remove_Estacionamento(fi, a[9]);
	imprime_Fila(fi);
    insere_Estacionamento(fi, a[9]);
   	remove_Estacionamento(fi, a[6]);

    libera_Fila(fi);

    return 0;
}
