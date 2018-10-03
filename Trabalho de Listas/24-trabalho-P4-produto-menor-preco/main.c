#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"
int produtoMenorPreco(Lista* li1) {
    int cod;
    float menor;
    Lista* li_temp = cria_lista();
    struct aluno aluno_insere;

    consulta_lista_pos(li1, 1, &aluno_insere);
    menor = aluno_insere.preco;
    cod = aluno_insere.codigo;

    while (!lista_vazia(li1)) {
        consulta_lista_pos(li1, 1, &aluno_insere);

        if (aluno_insere.preco < menor){
            menor = aluno_insere.preco;
            cod = aluno_insere.codigo;
        }
        insere_lista_final(li_temp, aluno_insere);
        remove_lista_inicio(li1);
    }

    while (!lista_vazia(li_temp)) {
        consulta_lista_pos(li_temp, 1, &aluno_insere);
        insere_lista_final(li1, aluno_insere);
        remove_lista_inicio(li_temp);
    }
    printf("\n-------------------------------\nProduto de Menor Preco:");

    consulta_lista_pos(li1, cod, &aluno_insere);
    printf("\nCodigo do Produto: %d", aluno_insere.codigo);
    printf("\nNome do Produto: %s", aluno_insere.nome);
    printf("\nPreço do Produto: %f", aluno_insere.preco);
    printf("\nQuantidade Disponível: %d", aluno_insere.qtde);

    printf("\n-------------------------------");

    libera_lista(li_temp);
	return 1;
}

int main(){
    struct aluno al, a[4] = {{2,"Oleo",9.5, 20},
                             {4,"Arroz",7.5, 40},
                             {1,"Feijao",8.7, 10},
                             {3,"Macarrao",5.7, 30}
                            };
    Lista* li = cria_lista();

    int i;
    for(i=0; i < 4; i++)
        insere_lista_ordenada(li, a[i]);

    imprime_lista(li);

    produtoMenorPreco(li);

    libera_lista(li);
    return 0;
}

