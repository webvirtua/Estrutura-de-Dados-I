#include<stdio.h>
#include<stdlib.h>
#include "Reseva.h" //inclui minha interface
#define QUADRAS 8

int alocacao(int *quadras){
    *quadras = (int)calloc(QUADRAS, sizeof(int));

    if(quadras == NULL){
        printf("Memoria insuficiente");
    }

    for(int i = 0; i <= QUADRAS;  i ++){
        *(quadras+i) = 0;
    }

    return quadras;
}

void quadrasDisponiveis(int *quadras){
    printf("RELATORIO DAS RESERVAS:\n");

    for(int i = 0; i <= QUADRAS;  i ++){
        if(quadras[i] == 0){
            printf("Quadra %i esta disponivel\n", i + 1);
        }else{
            printf("Quadra %i esta indisponivel\n", i + 1);
        }
    }
    printf("\n\n");
}

void reservarQuadra(int *quadras){
    int reserva, count;
    for(int i = 0; i <= QUADRAS;  i ++){
        if(*(quadras+i) == 0){
            printf("Quadra %i esta disponivel\n", i + 1);
        }
        count = count + quadras[i];
    }

    if(count == QUADRAS + 1){
        printf("\n==> Todas as quadras estao reservadas: <==\n\n");
    }else{
        printf("Digite o numero da quadra que deseja reservar:\n");
        scanf("%i", &reserva);

        if(*(quadras+(reserva - 1)) == 1){
            printf("\n=> Quadra %i ja esta reservada:\n\n", reserva);
            reservarQuadra(quadras);
        }else{
            *(quadras+(reserva - 1)) = 1;
        }
    }
}

void cancelarReserva(int *quadras){
    int reserva, count;
    for(int i = 0; i <= QUADRAS;  i ++){
        if(quadras[i] == 1){
            printf("Quadra %i esta reservada\n", i + 1);
        }
        count = count + quadras[i];
    }

    if(count == 0){
        printf("\n==> Nenhuma quadra foi reservada: <==\n\n");
    }else{
        printf("Digite o numero da quadra que deseja cancelar a reserva:\n");
        scanf("%i", &reserva);

        *(quadras+(reserva - 1)) = 0;
    }
}
int opcoes(int acao, int *quadras){
    switch(acao){
        case 0:
            acao = 0;
            break;
        case 1:
            printf("Fazer Reserva?\n");
            reservarQuadra(quadras);
            break;
        case 2:
            printf("Cancelar Reserva?\n");
            cancelarReserva(quadras);
            break;
        default:
            printf("\nOpcao não existe\n");
    }

    quadrasDisponiveis(quadras);

    printf("Para sair digite 0, para opcoes digite 1\n");
    scanf("%d", &acao);

    return acao;
}

