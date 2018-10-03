#include <stdio.h>
#include <stdlib.h>
#include "Decola.h";
int main(){
    int i;

    struct aluno al,a[5] = {
                               {1001, "Boeing 787", 330},
                               {2002, "Airbus A340", 380},
                               {3003, "Ilyushin Il-96", 350},
                               {4004, "Boeing 747", 585},
                               {5005, "Airbus A380", 853}
                           };

    Fila* fi = cria_Fila();

    printf("---------------------------------\n");
    printf("Avioes entrando na fila de espera");
    printf("\n---------------------------------\n");

    for(i = 0; i < 4; i++){
        insere_Fila(fi, a[i]);
        if(Fila_vazia(fi))
            printf("Erro!!!!!!\n");
    }
    printf("\nQuantidade de Avioes aguardando na fila para decolar: %d\n", tamanho_Fila(fi));
    printf("--------------------------------------\n\n");

    remove_Fila(fi);
    remove_Fila(fi);
    remove_Fila(fi);
    printf("\n");
    insere_Fila(fi, a[4]);
    printf("\nQuantidade de Avioes aguardando na fila para decolar: %d\n", tamanho_Fila(fi));
    printf("\n-------------------------------------------\n");
    printf("Lista de todos os avioes na fila de espera");
    printf("\n-------------------------------------------\n");

    imprime_Fila(fi);

    printf("Quantidade de Avioes na fila de espera: %d\n", tamanho_Fila(fi));
    printf("-------------------------------------------\n");

    printf("\nCaracteristicas do primeiro aviao da fila:\n");
    printf("--------------------------------------\n");
    consulta_Fila(fi, &al);
    printf(" Numero de identificacao: %d \n Modelo do aviao: %s \n Capacidade: %d pessoas\n", al.numId, al.nome, al.capacidade);
    printf("--------------------------------------\n\n");

    libera_Fila(fi);

    return 0;
}
