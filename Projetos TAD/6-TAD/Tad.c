#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Tad.h" //inclui os prototipos minha "biblioteca"
//Definição do tipo de dados
struct ponto{
    float x;
    float y;
};
//Aloca e retorna um ponto com coordenadas "x" e "y"
Ponto* pto_cria(float x, float y){
    Ponto* p = (Ponto*)malloc(sizeof(Ponto));

    if(p != NULL){
        p->x = x;
        p->y = y;
    }
    printf("Atruibuindo valores\n");
    printf("Valor de x = %f\n", x);
    printf("Valor de y = %f\n", y);
    printf("Valor de p->x = %f\n", p->x);
    printf("Valor de p->y = %f\n\n", p->y);
    return p;
}
//Libera a memória alocada para um ponto
void pto_libera(Ponto* p){
    free(p);
    printf("Ponteiro %i liberado\n", p);
}
//Recupera, por referência, o valor de um ponto
int pto_acessa(Ponto* p, float* x, float* y){
    if(p == NULL){
        return 0;
    }

    *x = p->x;
    *y = p->y;

    printf("Acessando valores\n");
    printf("Acessa de *x = %f\n", *x);
    printf("Acessa de *y = %f\n", *y);
    printf("Acessa de p->x = %f\n", p->x);
    printf("Acessa de p->y = %f\n\n", p->y);

    return 1;
}
//Atribui a um ponto as coordenadas "x" e "y"
int pto_atribui(Ponto *p, float x, float y){
    if(p == NULL){
        return 0;
    }

    p->x = x;
    p->y = y;

    printf("Atruibuindo novos valores\n");
    printf("Atribui de *x = %f\n", x);
    printf("Atribui de *y = %f\n", y);
    printf("Atribui de p->x = %f\n", p->x);
    printf("Atribui de p->y = %f\n\n", p->y);

    return 1;
}
//Calcula a distância entre dois pontos
float pto_distancia(Ponto* p1, Ponto* p2){
    if(p1 == NULL || p2 == NULL){
        return -1;
    }

    float dx = p1->x - p2->x;
    float dy = p1->y - p2->y;

    printf("Distancia dos pontos\n");
    printf("p1->x = %f\n", p1->x);
    printf("p1->y = %f\n", p1->y);
    printf("p2->x = %f\n", p2->x);
    printf("p2->x = %f\n\n", p2->y);

    return sqrt(dx * dx + dy * dy);
}
