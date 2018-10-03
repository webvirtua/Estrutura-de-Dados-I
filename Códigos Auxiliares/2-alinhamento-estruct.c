#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//fim de organização de código, como SGDS
struct endereco
{
    char rua[50];
    int numero;
};

struct pessoa
{
    char nome[50];
    int idade;
    struct endereco ender; //traz o endereço
};

int main()
{
	struct pessoa p;

	strcpy(p.nome, "Joao");
	p.idade = 35;
	strcpy(p.ender.rua, "Rua 55-A");
	p.ender.numero = 101;

	printf("p.nome: %s\n", p.nome);
	printf("p.ender.rua: %s\n", p.ender.rua);
	printf("p.ender.numero: %d\n", p.ender.numero);
	printf("p.idade: %d\n", p.idade);



}


