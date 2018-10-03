#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Escreva uma função hm que converta minutos em horas-e-minutos.
A função recebe um inteiro mnts
e os endereços de duas variáveis inteiras, digamos h e m,
>e atribui valores a essas variáveis de modo que m seja menor que 60 e que 60*h + m seja igual a mnts.
Escreva também uma função main que use a função hm.
Escreva uma função mm que receba um vetor inteiro v[0..n-1]
e os endereços de duas variáveis inteiras, digamos min e max,
e deposite nessas variáveis o valor de um elemento mínimo e o valor de um elemento máximo do vetor.
Escreva também uma função main que use a função mm.
*/

int minToHoras(int mnts, int *h, int *m){
    printf("%d\n", mnts);
    printf("%d\n", *h);
    printf("%d\n", *m);

    if(mnts < 60){
        *m = &mnts;
    }

    if(mnts >= 60){
        *h = &mnts
    }

    return mnts;
}

int main()
{
    int h = 2;
    int m = 40;

    minToHoras(30, &h, &m);
}


