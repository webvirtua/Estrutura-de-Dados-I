struct palavra{
    char x[1];
};
//Definição do tipo Pilha
struct pilha{
    int qtd;
    struct palavra letras[4];
};
typedef struct pilha Pilha;

Pilha* criaAlocacao();
void liberaAlocacao(Pilha* p);
void inserePalavra(Pilha* p, struct palavra letras);
void inverte(Pilha* p);
void compara(Pilha* p);
