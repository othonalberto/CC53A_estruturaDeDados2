#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "abp_sort.h"

NoABP *alocaNo(int k) {
    NoABP *novo = (NoABP*)malloc(sizeof(NoABP));
    if(novo == NULL) return NULL;

    novo->chave = k;
    novo->esq = novo->dir = NULL;

    return novo;
}

NoABP *insereNo(NoABP **raiz, int k) {
    assert(raiz);

    if(*raiz == NULL) {
        *raiz = alocaNo(k);
        return *raiz;
    }

    if(k <= (*raiz)->chave)
        return insereNo(&((*raiz)->esq), k);
    else
        return insereNo(&((*raiz)->dir), k);
}

NoABP *passaVetorParaABP(int vetor[], int n, NoABP **raiz) {
    int i;
    for (i = 0; i < n; i++)
        insereNo(raiz, *(vetor+i));

    return *raiz;
}

int abp_sort(NoABP *raiz, int v[], int i) {
    if (raiz->esq != NULL)
        i = abp_sort(raiz->esq, v, i);
    
    v[i++] = raiz->chave;
 
    if (raiz->dir != NULL)
        i = abp_sort(raiz->dir, v, i);

    return i;
 
}

void ordena(int v[], int n) {
    if (v == NULL) return;

    NoABP *arvore = NULL;
    passaVetorParaABP(v, n, &arvore);
    abp_sort(arvore,v, 0);
}
