#include <stdio.h>
#include <stdlib.h>
#include "FilaEstatica.h"

#define MAX_ESTACIONAMENTO 6

void imprime_linha() {
	printf("------------------------------------------\n");
}

int existe_no_estacionamento(Fila* fi, struct carro al) {
		
	int existe = 0;		
	struct carro aux;
	
	Fila* f_aux = cria_Fila();
	
	while( !Fila_vazia(fi)) {
		
			
		consulta_Fila(fi, &aux);
		remove_Fila(fi);
		insere_Fila(f_aux, aux);
		
		if (!strcmp(al.placa, aux.placa)) {
			existe = 1;
		}
		
		
	}
	
	while( !Fila_vazia(f_aux)) {
		consulta_Fila(f_aux, &aux);
		remove_Fila(f_aux);
		insere_Fila(fi, aux);
	}
	

	
	
	return existe;	
}

void remove_Estacionamento(Fila* fi, struct carro al) {
	
}

void insere_Estacionamento(Fila* fi, struct carro al) {	
	imprime_linha();
	printf("Carro Chegando: %s\n", al.placa);	
	
	if (tamanho_Fila(fi) != MAX_ESTACIONAMENTO) {	
		insere_Fila(fi, al);
		imprime_Fila(fi);
	} else {
		printf("FILA CHEIA\n");
		imprime_linha();
	}
	
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
    
    char s1[10], s2[10];
       
    printf("-->>>>>>>>%d", strcmp(s1, s2));
    

    printf("\nSAIDA ESPERADA: ITEM (A)\n");
    imprime_linha();	
   	 for(int i=0; i < MAX_ESTACIONAMENTO; i++){
        insere_Estacionamento(fi, a[i]);        
    }
    insere_Estacionamento(fi, a[6]);
    
	

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
  
    
	/*
	printf("\nSAIDA ESPERADA: ITEM (C)\n");    
    remove_Estacionamento(fi, a[2]);
	insere_Estacionamento(fi, a[6]);
	remove_Estacionamento(fi, a[4]);
    remove_Estacionamento(fi, a[9]);
    insere_Estacionamento(fi, a[9]);
    remove_Estacionamento(fi, a[6]);
	*/
	
    libera_Fila(fi);
		
    system("pause");
    return 0;
}


