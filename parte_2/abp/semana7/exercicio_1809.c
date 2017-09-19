#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "exercicio_1809.h"

TNoABP *insere(TNoABP **raiz, int k) {
    if (*raiz == NULL) {
        *raiz = (TNoABP*)malloc(sizeof(TNoABP));
        if (*raiz == NULL) return NULL;

        (*raiz)->chave = k;
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;

        return *raiz;
    }

    if (k < (*raiz)->chave)
        return insere(&((*raiz)->esq), k);
    else
        return insere(&((*raiz)->dir), k); 
}

TNoABP *balanc(TNoABP **raiz) {
    assert(raiz);

    if (*raiz == NULL) return NULL;

    TNoABP *aux = *raiz;
    *raiz = aux->dir;
    aux->esq = NULL;
    aux->dir = NULL;
    (*raiz)->esq = aux;

    return *raiz;
    
}

void info(TNoABP *raiz) {
    printf("Mora em: %pValor-chave: %d; Esq: %p, Dir: %p\n", raiz, raiz->chave, raiz->esq, raiz->dir);

}
