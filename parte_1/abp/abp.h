typedef struct No {
    int chave;
    struct No *esq;
    struct No *dir;
} No;


No *aloca_no(int chave);

void imprime_no (No *no);
