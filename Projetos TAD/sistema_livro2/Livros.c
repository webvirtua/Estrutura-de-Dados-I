#include <stdio.h>
#include<stdlib.h>
#include "Livros.h"
#define MAXN 5
typedef struct{
    char titulo[50];
    char autor[30];
    char genero[10];
    int ano;
}livro;

int alocacao(p){
    livro *m = p;

    m = calloc(MAXN, sizeof(livro));

    if (!m){
        printf("Calloc não foi definido.\n");
    }
    return m;
}

void criaLivro(Livros *aloc){
    livro *m = aloc;

    livro Livros;

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
}

obtemGenero(Livros *aloc, int numAloc){
    livro *m = aloc;

    livro Livros;

    printf("\n===========================\n");
    printf("GENERO DO LIVRO\n");
    printf("Genero: %s", m[numAloc].genero);
}

obtemAutor(Livros *aloc, int numAloc){
    livro *m = aloc;

    livro Livros;

    printf("\n===========================\n");
    printf("AUTOR DO LIVRO\n");
    printf("Genero: %s", m[numAloc].autor);
}

obtemTitulo(Livros *aloc, int numAloc){
    livro *m = aloc;

    livro Livros;

    printf("\n===========================\n");
    printf("TITULO DO LIVRO\n");
    printf("Genero: %s", m[numAloc].titulo);
}

obtemAno(Livros *aloc, int numAloc){
    livro *m = aloc;

    livro Livros;

    printf("\n===========================\n");
    printf("ANO DO LIVRO\n");
    printf("Genero: %i", m[numAloc].ano);
    printf("\n===========================\n");
}

verificaNoModernismo(Livros *aloc, int numAloc){
    livro *m = aloc;

    livro Livros;

    for(int i = 0; i < MAXN; i++) {
        if(m[numAloc].ano < 1930){
            return 0;
        }else if(m[numAloc].ano >= 1930 && m[numAloc].ano <= 1945){
            return -1;
        }else if(m[numAloc].ano > 1945){
            return 1;
        }
    }
}
