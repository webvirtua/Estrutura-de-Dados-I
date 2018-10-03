typedef struct ponto Ponto; // struct ponto sera reconhecido como Ponto
//Cria um novo ponto
Ponto* pto_cria(float x, float y); //cria e devolve um ponteiro
//Libera um ponto
void pto_libera(Ponto* p);
//Acessa os valores "x" e "y" de um ponto
int pto_acessa(Ponto* p, float* x, float* y);
//atribui valores
int pto_atribui(Ponto* p, float x, float y);
//Calcula a distância entre dois pontos
float pto_distancia(Ponto* p1, Ponto* p2);
