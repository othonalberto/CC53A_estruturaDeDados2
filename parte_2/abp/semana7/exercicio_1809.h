typedef struct TNoABP {
    int chave;
    struct TNoABP *esq;
    struct TNoABP *dir;
} TNoABP;

TNoABP *insere(TNoABP **raiz, int k);

TNoABP *balanc(TNoABP **raiz);

void info(TNoABP *raiz);
