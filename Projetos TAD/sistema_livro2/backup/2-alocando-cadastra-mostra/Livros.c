#include <stdio.h>
#include<stdlib.h>
#include "Livros.h"
#define MAXN 2
typedef struct{
    char titulo[50];
    char autor[30];
    char genero[10];
    int ano;
}livro;

Livros *alocacao(){
    livro *m;

    m = calloc(MAXN, sizeof(livro));

    if (!m){
        printf("Calloc não foi definido.\n");
    }
    return m;
}

void criaLivro(){
    livro *m = alocacao();

    //livro *m;

    livro Livros;

    //m = calloc(MAXN, sizeof(livro));

    //if (!m){
        //printf("Calloc não foi definido.\n");
    //}

    for(int i = 0; i < MAXN; i++){
        printf("\nEntre com o titulo do livro: ");
        scanf("%s%*c", Livros.titulo);
        printf("\nEntre com a autor do livro: ");
        scanf("%s%*c", Livros.autor );
        printf("\nEntre com o genero do livro: ");
        scanf("%s%*c", Livros.genero);
        printf("\nEntre com a ano do livro: ");
        scanf("%i", &Livros.ano);

        *(m+i) = Livros;
    }

    for(int i = 0; i < MAXN; i++){
        printf("%d ", *(m+i) );
    }

    printf("\n===========================\n");

    for(int i = 0; i < MAXN; i++) {
        printf("LIVRO %i\n", i + 1);
        printf("---------\n");
        printf("Titulo: %s\n", m[i].titulo);
        printf("Autor:  %s\n", m[i].autor);
        printf("Genero: %s\n", m[i].genero);
        printf("Ano:    %d\n", m[i].ano);
        printf("===========================\n");
    }

    printf("tes 1: %s\n", m[0].titulo);
    printf("tes 2: %s\n", m[1].titulo);

    free(m);
}
