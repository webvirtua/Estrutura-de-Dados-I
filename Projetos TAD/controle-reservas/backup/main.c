#include<stdio.h>
#include<stdlib.h>
#include "Reseva.h" //inclui minha interface

int main(){
    int *quadras, acao = 10;

    alocacao(quadras);

    quadrasDisponiveis(quadras);

    while(acao != 0){
        printf("Escolha uma opcao\n");
        printf(" 1 fazer reserva\n");
        printf(" 2 cancelar reserva\n");
        printf(" 0 Nenhuma acao\n\n");
        scanf("%i", &acao);

        opcoes(acao, quadras);
    }

    printf("\nSaiu do programa!\n");
}
