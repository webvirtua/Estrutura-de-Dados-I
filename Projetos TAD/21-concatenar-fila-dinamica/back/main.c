#include <stdio.h>
#include <stdlib.h>
//estrutura
struct no
{
	int info;
	struct no *prox;
};
//funções
void inserirDados(struct no *head, int valor);//inserir dados
void selecionarLista(int *listaTrabalho);//selecionar lista
void imprimirLista(struct no *head);//imprimir listas
void concatenarListas(struct no *lista1, struct no *lista2); //concatenas listas
void menu();//menu
//função principal
int main(int argc, char *argv)
{
	struct no *head, *head2; //utilizando 2 listas circulares
	int op, selectList, valor;

	if((head = malloc(sizeof(struct no))) == NULL)//erro de memoria 1
	{
		printf("\nMemory Failure. . .\n");
	}
	else
	{

		if((head2 = malloc(sizeof(struct no))) == NULL)//erro de memoria 2
		{
			printf("\nMemory Failure. . .\n");
		}
		else
		{
			head->prox = head;
			head2->prox = head2;

			//escolher lista para trabalho
			selecionarLista(&selectList);
			do{
				system("CLS");
				menu();
				scanf("%d",&op);
				switch(op)
				{
					case 0:
						break;
					case 1://selecionar lista
						selecionarLista(&selectList);
						break;
					case 2://inserir dados nas listas
						switch(selectList)
						{
							case 1:
								inserirDados(head, valor);//lista 1
								break;
							case 2:
								inserirDados(head2, valor);//lista 2
								break;
						}
						break;
					case 3://imprimir listas
						switch(selectList)
						{
							case 1:
								imprimirLista(head);//lista 1
								break;
							case 2:
								imprimirLista(head2);//lista 2
								break;
						}
						break;
					case 4://concatenar listas
						concatenarListas(head, head2);
						break;
					default:
						printf("\nDigite uma op%c%co V%clida!\n",135,198,160);
                		break;
				}
				//getch();
			}
			while(op!=0);
			return 0;
		}
	}
}
//------------------------------------------------------------------------------
void selecionarLista(int *listaTrabalho) //selecionar lista
{
	do
	{
		printf("\n1- Lista de Trabalho 01 || 2- Lista de Trabalho 02: ");
		scanf("%d",listaTrabalho);
	}
	while((*listaTrabalho !=1) && (*listaTrabalho !=2)); //bloqueio de opções erradas
}
//------------------------------------------------------------------------------
void inserirDados(struct no *head, int valor)//inserir dados
{
	struct no *pNow, *aux;

	printf("\nInserir Elementos: ");
	scanf("%d",&valor);

	if((pNow = malloc(sizeof(struct no))) == NULL)//error
	{
		printf("\nMemory Failure. . .\n");
	}
	else
	{
		pNow->info = valor; //aloca valor
		aux = head;//auxiliar

		//enquanto o proximo valor for menor que o valor digitado então insere na ordem
		while(aux->prox->info < valor)
		{
			aux = aux->prox;
		}

		//liga os ponteiros
		pNow->prox = aux->prox;
		aux->prox = pNow;
	}
}
//------------------------------------------------------------------------------
void imprimirLista(struct no *head)//imprimir listas
{
	struct no *p;
	int empty = 0; // S/N?
	p = head->prox;
	//enquanto p não for nulo
	while(p!= head)
	{
		printf("\n%d",p->info);//imprime o valor atual
		p = p->prox;//passa para o proximo registro
		empty = 1;
	}
	if(empty == 0) //verifica se a lista é vazia ou não
	{
		printf("\nLista Vazia!\n");
	}
}
//------------------------------------------------------------------------------
void concatenarListas(struct no *lista1, struct no *lista2)//concatenar listas
{
	struct no *aux1, *aux2;

	//auxiliares
	aux1 = lista1;
	aux2 = lista2;

	if((lista1->prox == lista1) && (lista2->prox == lista2))//ambas listas vazias
	{
		printf("\nListas (1 & 2) Vazias!");
	}
	else
	{
		if(lista1->prox == lista1) //lista 1 vazia
		{
			printf("\nLista 1 Vazia!\n");
		}
		else if(lista2->prox == lista2) //lista 2 vazia
		{
			printf("\nLista 2 Vazia!\n");
		}
		else  //nenhuma está vazia então...
		{
			//concatenando as listas
			if(lista2->prox != lista2)
			{
				//lista 1
				while(aux1->prox!=lista1)
				{
					aux1 = aux1->prox;
				}
				aux1->prox = aux2->prox;

				//lista 2
				while(aux2->prox != lista2)
				{
					aux2 = aux2->prox;
				}
				//atualiza ponteiros
				aux2->prox = lista1;
				lista2->prox = lista2;
			}
			//msg de okay e imprime as listas concatenadas (após isso, a lista 2 fica vazia)
			printf("\n\t\t>> Listas concatenas com Sucesso << ");
			imprimirLista(lista1);
		}
	}
}
//------------------------------------------------------------------------------
void menu()//menu de opções
{
	printf("\n1) Selecionar Lista de Trabalho");
	printf("\n2) Inserir Elementos");
	printf("\n3) Imprimir Lista");
	printf("\n4) Concatenar Listas");
	printf("\n\n0) Sair: ");
}
