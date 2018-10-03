#include <stdio.h>
#include <stdlib.h>
#include "PilhaSequencial.h"
int main(){
    struct aluno a[ALUNOS] = {{211,"Andre",9.5,7.8,8.5},
                         {425,"Ricardo",7.5,8.7,6.8},
                         {115,"Bianca",9.7,6.7,8.4},
                         {115,"Julia",10.0,9.7,9.9},
                         {335,"Ana",5.7,6.1,7.4}};
    Pilha* pi = cria_Pilha();
    printf("Tamanho => %d\n\n\n\n",tamanho_Pilha(pi));
    int i;
    for(i=0; i < ALUNOS; i++)
        insere_Pilha(pi,a[i]);

    imprime_Pilha(pi);
    printf("Tamanho ==> %d\n\n\n\n",tamanho_Pilha(pi));

    for(i=0; i < ALUNOS; i++)
        remove_Pilha(pi);
    printf("Tamanho ===> %d\n\n\n\n",tamanho_Pilha(pi));
    imprime_Pilha(pi);

    for(i=0; i < ALUNOS; i++)
        insere_Pilha(pi,a[i]);

    printf("Tamanho ====> %d\n\n\n\n",tamanho_Pilha(pi));
    imprime_Pilha(pi);

    escolheNaPilha(pi);

    libera_Pilha(pi);
    system("pause");
    return 0;
}
