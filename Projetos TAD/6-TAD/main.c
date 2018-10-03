#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Tad.h" //inclui os prototipos minha "biblioteca"

int main(){
    float d, n1 = 5, n2 = 8, n3 = 5, n4 = 5;
    Ponto *p, *q;

    p = pto_cria(n1, n2);
    q = pto_cria(n3, n4);

    d = pto_distancia(p, q);
    printf("\nDistancia entre dois pontos: %f\n\n", d);

    pto_acessa(p, &n1, &n2);

    pto_atribui(p, 25, 70);
    pto_atribui(q, 16, 17);

    pto_libera(p);
    pto_libera(q);

    printf("\n-------------PONTEIROS COMUNS----------------\n");

    struct pessoa{
        char nome[50], rua[50];
        int idade, numero;
    };

    struct pessoa p1, p4 = {"Ze", "Alameda C", 60, 1};

	strcpy(p1.nome, "Ricardo");
	strcpy(p1.rua, "Rua 1");
	p1.idade = 31;
	p1.numero = 101;

	printf("p1.nome: %s\n", p1.nome);
	printf("p1.rua: %s\n", p1.rua);
	printf("p1.numero: %d\n", p1.numero);
	printf("p1.idade: %d\n", p1.idade);

	printf("\n----------------------\n");

	printf("p1.nome: %s\n", p4.nome);
	printf("p1.rua: %s\n", p4.rua);
	printf("p1.numero: %d\n", p4.numero);
	printf("p1.idade: %d\n", p4.idade);

	printf("\n-----------------------------\n");

    return 0;
}
