#include <stdio.h>
#include <stdlib.h>
typedef struct{
        char titulo[50];
        char autor[30];
        char genero[10];
        int ano;
}livro;

void criaLivro(){

}

void obtemGenero(){

}

void obtemAutor(){

}

void obtemTitulo(){

}

void obtemAno(){

}

void verificaNoModernismo(){

}

int main(){
    int limite = 2;
    livro *vet;

    livro livros;
    livro vetor[limite];

    vet = calloc(limite, sizeof(livro));
    printf("tamanho: %i\n", sizeof(vet));

    if (!vet){
        printf("Calloc não foi definido.\n");
    }


    printf("===livros==>: %i\n", livros);
    printf("===vetor 1==>: %i\n", vetor);
    printf("===vetor 2==>: %i\n", vetor+1);
    printf("===vet 1==>: %i\n", vet);
    printf("===vet 2==>: %i\n", vet+1);

    for(int i = 0;i < limite; i++){
        printf("\nEntre com o titulo do livro: ");
        scanf("%s%*c", livros.titulo);
        printf("\nEntre com a autor do livro: ");
        scanf("%s%*c", livros.autor );
        printf("\nEntre com o genero do livro: ");
        scanf("%s%*c", livros.genero);
        printf("\nEntre com a ano do livro: ");
        scanf("%i", &livros.ano);
        vetor[i] = livros;
    }
    printf("\n===========================\n");

    for(int i = 0; i < limite; i++) {
        printf("LIVRO %i\n", i + 1);
        printf("---------\n");
        printf("Titulo: %s\n", vetor[i].titulo);
        printf("Autor:  %s\n", vetor[i].autor);
        printf("Genero: %s\n", vetor[i].genero);
        printf("Ano:    %d\n", vetor[i].ano);
        printf("===========================\n");
    }
}
