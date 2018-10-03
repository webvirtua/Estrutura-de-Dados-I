#include <stdio.h>
#include <stdlib.h>
#include "FilaEstatica.h"
#include <string.h>
#define MAX_ESTACIONAMENTO 6

void imprime_linha() {
	printf("------------------------------------------\n");
}

int existe_no_estacionamento(Fila* fi, struct carro al) {
	int i, resposta, tam, existe = 0;	
	struct carro alAux;	
	tam = tamanho_Fila(fi);

	Fila* fiAux = cria_Fila();	

	//Verifica na fila Fi se o carro ja esta no estacionamento e faz um backup na fiAux
	for (i = 0; i < tam; i++) {
		consulta_Fila(fi,&alAux);
		insere_Fila(fiAux, alAux);
		remove_Fila(fi);

		
		if (strcmp(al.placa,alAux.placa) == 0) {
			existe = 1;
			
		}
	}

	//Reconstroi a fila fi atraves do backup fiAux
	for (i = 0; i < tam; i++) {
		consulta_Fila(fiAux,&alAux);
		insere_Fila(fi, alAux);
		remove_Fila(fiAux);
	}

	libera_Fila(fiAux);
	return existe;	
}

void remove_Estacionamento(Fila* fi, struct carro al) {
	int i,tam,tam2;
	struct carro alAux;
	tam = tamanho_Fila(fi);
	
	imprime_linha();
	if (existe_no_estacionamento(fi, al) == 1) {
		Fila* fiAux = cria_Fila();
		
	//Verifica na fila Fi se o carro ja esta no estacionamento e faz um backup na fiAux
		for (i = 0; i < tam; i++) {
			consulta_Fila(fi,&alAux);
			alAux.qtde++;
			if (strcmp(al.placa,alAux.placa) == 0) {
				remove_Fila(fi);
				break;
			}
			insere_Fila(fiAux, alAux);
			remove_Fila(fi);
		}
	
		tam2 = tamanho_Fila(fi);

		//Consulta os demais carros da fila Fi para depois reconstrui-la pela fiAux
		for (i = 0; i < tam2; i++) {
			consulta_Fila(fi,&alAux);
			insere_Fila(fiAux, alAux);
			remove_Fila(fi);
		}
		
		
		//Reconstroi a fila fi atraves do backup fiAux
		for (i = 0; i < tam-1; i++) {
			consulta_Fila(fiAux,&alAux);
			insere_Fila(fi, alAux);
			remove_Fila(fiAux);
		}
		
		printf("O carro %s saiu\n", al.placa);
		imprime_Fila(fi);
		libera_Fila(fiAux);
	} else {
			printf("O CARRO = %s NAO FOI ENCONTRADO NO ESTACIONAMENTO!!!\n", al.placa);
		}
	
	imprime_linha();
}

void insere_Estacionamento(Fila* fi, struct carro al) {	
	if (Fila_cheia(fi)) return;
	if (existe_no_estacionamento(fi, al) == 1) {
		return;
	}
	
	insere_Fila(fi, al);
	printf("\nCarro de placa = %s entrando no estacionamento\n", al.placa);
	imprime_Fila(fi);
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


	printf("\nSAIDA ESPERADA: ITEM (C)\n");    
    remove_Estacionamento(fi, a[2]);
	insere_Estacionamento(fi, a[6]);
	remove_Estacionamento(fi, a[4]);
	remove_Estacionamento(fi, a[9]);
    insere_Estacionamento(fi, a[9]);
   	remove_Estacionamento(fi, a[6]);
   	imprime_linha();
   	imprime_Fila(fi);
   	imprime_linha();

    libera_Fila(fi);
		
    system("pause");
    return 0;
}


