#ifndef ARVORE_BINARIA
#define ARVORE_BINARIA

typedef struct No {
    int chave;
    struct No *esq;
    struct No *dir;
} No;


// aloca um nó folha do tipo No
No *aloca_no(int chave);

// procura o campo correto para a inserção de um novo nó
No **retorna_campo(No *arvore, int chave);

// utilizando aloca_no e retorna_pai, insere um novo nó na arvore
No *insere_no(No **arvore, int chave);

// função recursiva para inserção
No *insere_rec(No **arvore, int chave);

// busca um nó com campo chave x
No *busca_no(No *arvore, int chave);

// imprime endereço, valor chave, filho esquerdo e filho direito de um nó
void imprime_no (No *no);

#endif
