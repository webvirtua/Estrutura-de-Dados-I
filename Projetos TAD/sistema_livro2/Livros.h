typedef struct livro Livros;
//Aloca memoria
int alocacao(p);
//Cria registro de cada livro
void criaLivro(Livros *aloc);
//Busca livro pelo genero
void obtemGenero(Livros *aloc, int numAloc);
//Busca livro pelo autor
void obtemAutor(Livros *aloc, int numAloc);
//Busca livro pelo titulo
void obtemTitulo(Livros *aloc, int numAloc);
//Busca livro pelo ano
void obtemAno(Livros *aloc, int numAloc);
//Verifica se um livro pertence a um periodo
void verificaNoModernismo(Livros *aloc, int numAloc);
