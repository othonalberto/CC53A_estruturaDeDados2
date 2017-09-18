/* Enunciado do problema: 
 * Implemente o procedimento ordena(int v[], int n) que põe em ordem crescente o vetor v com n elementos.
 * A ordenação deve ser efeita por intermédio de uma árvore binária de pesquisa.
 */

typedef struct NoABP {
    int chave;
    struct NoABP *esq;
    struct NoABP *dir;
} NoABP;

NoABP *alocaNo(int k);

NoABP *insereNo(NoABP **raiz, int k);

NoABP *passaVetorParaABP(int vetor[], int n, NoABP **raiz);

int abp_sort(NoABP *raiz, int v[], int i);

void ordena(int v[], int n);

