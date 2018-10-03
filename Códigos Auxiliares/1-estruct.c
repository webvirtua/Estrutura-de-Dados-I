#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa
{
    char nome[50], rua[50];
    int idade, numero;
};

int main()
{
	struct pessoa p1, p2, p3, p5, p4 = {"Ze", "Alameda C", 60, 1};

	strcpy(p1.nome, "Ricardo");
	strcpy(p1.rua, "Rua 1");
	p1.idade = 31;
	p1.numero = 101;

	printf("p1.nome: %s\n", p1.nome);
	printf("p1.rua: %s\n", p1.rua);
	printf("p1.numero: %d\n", p1.numero);
	printf("p1.idade: %d\n", p1.idade);

	printf("\n-------------Pode fazer como array----------------\n");

	struct pessoa p = {"Maria", "Avenida A", 19, 55};

	printf("p.nome: %s\n", p.nome);
	printf("p.rua: %s\n", p.rua);
	printf("p.numero: %d\n", p.numero);
	printf("p.idade: %d\n", p.idade);

	printf("\n-----------------------------\n");

    printf("p4.nome: %s\n", p4.nome);
	printf("p4.rua: %s\n", p4.rua);
	printf("p4.numero: %d\n", p4.numero);
	printf("p4.idade: %d\n", p4.idade);

	printf("\n---------Funcao strcpy copia variavel da direita pra dentro da esquerda----------\n");

	strcpy(p3.nome, p1.nome);
	printf("p3.nome recebe o valor de p1.nome: %s\n", p3.nome);

	printf("\n---------Copia todos os dados do estruct----------\n");

	p2 = p1;

	printf("p2.nome: %s\n", p2.nome);
	printf("p2.rua: %s\n", p2.rua);
	printf("p2.numero: %d\n", p2.numero);
	printf("p2.idade: %d\n", p2.idade);

	printf("\n---------Pegando nome como input----------\n");

	printf("digite um nome:");
	gets(p5.nome); //esta dando um erro, mas esta certo
	printf("p5.nome: %d\n", p5.nome);


    /*
	p1.idade = 31;
	scanf("%d", &p1.numero); //comando de leitura
	gets(p1.nome); //comando de leitura
	p1.numero = p1.numero + p1.idade - 100;

	printf("p1.idade: %d\n", p1.idade);
	printf("p1.idade: %d\n", p1.numero);
	printf("p1.idade: %d\n", p1.nome);
	*/
}

