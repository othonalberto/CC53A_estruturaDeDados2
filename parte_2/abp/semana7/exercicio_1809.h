/* ENUNCIADO DO EXERCÍCIO PREPARATÓRIO
 *
 * Seja o ponteiro raiz um ponteiro para o nó raiz da seguinte árvore binária de
 * pesquisa (1 (2 (3)). Implemente um procedimento que balanceie a árvore
 * mencionada. Faça as suposições necessárias.
 */

typedef struct TNoABP {
    int chave;
    struct TNoABP *esq;
    struct TNoABP *dir;
} TNoABP;

TNoABP *insere(TNoABP **raiz, int k);

TNoABP *balanc(TNoABP **raiz);

void info(TNoABP *raiz);
