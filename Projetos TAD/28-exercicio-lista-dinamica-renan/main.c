#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncadDupla.h"
int main(){
    struct aluno a1 = {1,"Andre",9.5,7.8,8.5};
    struct aluno v[5] = {
						{7,"Maria",9,8,5},
    					{9,"Bruna",9,8,5},
    					{5,"Carlos",9,8,5},
    					{8,"Marcos",9,8,5},
    					{6,"Silvia",9,8,5},
					};

    Lista* li = cria_lista();

    insere_lista_ordenada(li, a1);
    insere_lista_ordenada(li, v[0]);
    insere_lista_ordenada(li, v[1]);
    insere_lista_ordenada(li, v[2]);
    insere_lista_ordenada(li, v[3]);
    insere_lista_ordenada(li, v[4]);

	printf("TAM %d\n", tamanho_lista(li));

    imprime_lista(li);


    struct aluno aluno_retorno;
    consulta_lista_mat(li, 5, &aluno_retorno);
    printf("=>%s\n", aluno_retorno.nome);

    modifica_lista_mat(li, 5, "Cris do Brasil");


    consulta_lista_mat(li, 5, &aluno_retorno);
    printf("==>>%s\n", aluno_retorno.nome);

    printf("\n\n*****************\n\n");
    imprime_lista(li);
    printf("\n\n*****************\n\n");


   imprime_ordem_inversa(li);




    libera_lista(li);
    system("pause");
    return 0;
}

