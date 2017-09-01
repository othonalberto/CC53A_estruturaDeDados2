#include <stdlib.h>
#include "binaria.h"
#include <assert.h>

NoArvBinaria *buscaArvBinRec(NoArvBinaria *raiz, int k) {
    if (raiz == NULL) return NULL;

    if (raiz->chave == k) return raiz;

    if (k < raiz->chave)
        return buscaArvBinRec(raiz->esq, k);
    else
        return buscaArvBinRec(raiz->dir, k);
}

NoArvBinaria *buscaArvBinIterativa(NoArvBinaria *raiz, int k) {
    while (raiz != NULL) {
        if (raiz->chave == k)
            return raiz;
        
        if (k < raiz->chave)
            raiz = raiz->esq;
        else
            raiz = raiz->dir;
    }

    return NULL;
}

NoArvBinaria *buscaEnderecoDoMenor(NoArvBinaria *raiz) {
    if (raiz == NULL) return NULL;

    while (raiz->esq != NULL)
        raiz = raiz->esq;

    return raiz;
}

NoArvBinaria *buscaEnderecoDoMaior(NoArvBinaria *raiz) {
    if (raiz == NULL) return NULL;

    while (raiz->dir != NULL)
        raiz = raiz->dir;

    return raiz;
}

NoArvBinaria **buscaEnderecoDoPonteiro(NoArvBinaria **raiz, int k) {
    assert(raiz);

    if (*raiz == NULL) return NULL;

    if ((*raiz)->chave == k) return raiz;

    if (k < (*raiz)->chave)
        return buscaEnderecoDoPonteiro(&((*raiz)->esq), k);
    else
        return buscaEnderecoDoPonteiro(&((*raiz)->dir), k);
}

NoArvBinaria **buscaEnderecoDoPonteiroDoMenor(NoArvBinaria **raiz) {
    assert(raiz);
    
    if (*raiz == NULL) return NULL;

    if ((*raiz)->esq == NULL)
        return raiz;
    else
        return buscaEnderecoDoPonteiroDoMenor(&((*raiz)->esq));
}

NoArvBinaria **buscaEnderecoDoPonteiroDoMaior(NoArvBinaria **raiz) {
    assert(raiz);

    if (*raiz == NULL) return NULL;

    if ((*raiz)->dir == NULL)
        return raiz;
    else
        return buscaEnderecoDoPonteiroDoMaior(&((*raiz)->dir));
}

void removeFolha(NoArvBinaria **folha) {
    assert(folha);

    if (*folha == NULL) return;

    NoArvBinaria *aux = *folha;
    *folha = NULL;
    free(aux);
}

void removeNoComSomenteUmFilho(NoArvBinaria **raiz) {
    assert(raiz);

    if ((*raiz)->esq != NULL) {
        NoArvBinaria *aux = *raiz;
        *raiz = (*raiz)->esq;
        free(aux);
    } else {
        NoArvBinaria *aux = *raiz;
        *raiz = (*raiz)->dir; 
        free(aux); 
    }
}

NoArvBinaria *insereArvBinRec(NoArvBinaria **raiz, int k) {
    assert(raiz);

    if (*raiz == NULL) {
        *raiz = (NoArvBinaria*)malloc(sizeof(NoArvBinaria));
        if (*raiz == NULL) return NULL;

        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
        (*raiz)->chave = k;

        return *raiz;
    }

    if (k < (*raiz)->chave)
        return insereArvBinRec(&((*raiz)->esq), k);
    else if (k > (*raiz)->chave)
        return insereArvBinRec(&((*raiz)->dir), k);
    else
        return *raiz; //nó já existe
}

NoArvBinaria *insereArvBinIterativa(NoArvBinaria **raiz, int k) {
    assert(raiz);

    while (*raiz != NULL) {
        if (k < (*raiz)->chave)
            *raiz = (*raiz)->esq;
        
        else if (k > (*raiz)->chave)
            *raiz = (*raiz)->dir;
        else
            return *raiz;
    }

    *raiz = (NoArvBinaria*)malloc(sizeof(NoArvBinaria));
    if(*raiz == NULL) return NULL;

    (*raiz)->esq = NULL;
    (*raiz)->dir = NULL;
    (*raiz)->chave = k;

    return *raiz;
}
void removeArvBinRec(NoArvBinaria **raiz, int k) {
    NoArvBinaria **aremover = buscaEnderecoDoPonteiro(raiz, k);
    NoArvBinaria *filho = NULL; 
    // Caso 1: nó folha
    if ((*aremover)->esq == NULL && (*aremover)->dir == NULL) {
       free(*aremover);
       *aremover = NULL;
       return;
    }

    // Caso 2: nó só com um filho
    if (((*aremover)->esq == NULL) != ((*aremover)->dir == NULL)) {
        if ((*aremover)->esq != NULL)
            filho = (*aremover)->esq;
        else
            filho = (*aremover)->dir;

        free(*aremover);
        *aremover = filho;
        return;
    }
    // Caso 3: nó com dois filhos 
    if ((*aremover)->esq && (*aremover)->dir) {
        NoArvBinaria **substituto = buscaEnderecoDoPonteiroDoMenor(&(*raiz)->dir);
        (*aremover)->chave = (*substituto)->chave;
        removeArvBinRec(substituto, (*substituto)->chave);
        return;
    }
}
