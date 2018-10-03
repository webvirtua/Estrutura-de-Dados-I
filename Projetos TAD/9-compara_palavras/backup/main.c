#include <stdio.h>
#include <stdlib.h>
#include "Compara.h"

int main(){
    struct palavra letra[4] = { {"A"}, {"B"}, {"C"}, {"D"} };

    Pilha* p = criaAlocacao();



    for(int i = 0; i < 4; i++){
        inserePalavra(p, letra[i]);
        printf("i = %i\n", i);
    }

    //liberaAlocacao(p);
    return 0;
}
