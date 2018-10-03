#include <stdio.h>
#include<stdlib.h>
#include "Livros.h"
#define MAXN 2

int main(int argc, char *argv[]) {
    int vetor[MAXN];
    int livro = 1;

    Livros *p = vetor;
    Livros *aloc = p;
    aloc = alocacao(aloc);

    criaLivro(aloc);

    obtemGenero(aloc, livro);

    obtemAutor(aloc, livro);

    obtemTitulo(aloc, livro);

    obtemAno(aloc, livro);

    verificaNoModernismo(aloc, livro);

    printf("\n\n");
}
