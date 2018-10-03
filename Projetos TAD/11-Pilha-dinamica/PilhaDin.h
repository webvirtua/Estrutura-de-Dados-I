struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};
//Definição do tipo Pilha
struct elemento{
    struct aluno dados;
    struct elemento* prox;
};
typedef struct elemento Elem;

typedef struct elemento* Pilha;

Pilha* cria_Pilha();

void libera_Pilha(Pilha* pi);

int consulta_topo_Pilha(Pilha* pi);

int insere_Pilha(Pilha* pi, struct aluno al);

int remove_Pilha(Pilha* pi);

int tamanho_Pilha(Pilha* pi);

int Pilha_vazia(Pilha* pi);

int Pilha_cheia(Pilha* pi);

void imprime_Pilha(Pilha* pi);
