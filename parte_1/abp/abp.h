typedef struct No {
    int chave;
    struct No *esq;
    struct No *dir;
} No;


No *aloca_no(int chave);

No *retorna_pai(No *arvore, int chave);

No *insere_no(No **arvore, int chave);

void imprime_no (No *no);
