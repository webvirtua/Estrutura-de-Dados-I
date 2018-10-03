#define LETRAS 4
struct aluno{
    char nome[LETRAS];
};

//Definição do tipo Pilha
struct pilha{
    int qtd;
    struct aluno dados[LETRAS];
};
typedef struct pilha Pilha;

Pilha* cria_Pilha();
void libera_Pilha(Pilha* pi);
int insere_Pilha(Pilha* x, struct aluno al);
int remove_Pilha(Pilha* pi);
int inverte_Pilha(Pilha* x, Pilha* temp, Pilha* copia);
int compara_Pilha(Pilha* x, Pilha* y);
int tamanho_Pilha(Pilha* pi);
void imprime_Pilha(Pilha* pi);

