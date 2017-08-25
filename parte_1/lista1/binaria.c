#include <stdlib.h>
#include "binaria.h"
#include <assert.h>

NoArvBinaria *buscaArvBinRec(NoArvBinaria *raiz, int k) {
    if(raiz == NULL) return NULL;

    if(raiz->chave == k) return raiz;

    if(k < raiz->chave)
        return buscaArvBinRec(raiz->esq, k);
    else
        return buscaArvBinRec(raiz->dir, k);
}

NoArvBinaria *buscaArvBinIterativa(NoArvBinaria *raiz, int k) {
    while(raiz != NULL) {
        if(raiz->chave == k)
            return raiz;
        
        if(k < raiz->chave)
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
    if(raiz == NULL) return NULL;

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

    if(*folha == NULL) return;

    NoArvBinaria *aux = *folha;
    free(aux);
    *folha = NULL;
}

/*
 * Assume que *raiz != NULL 
 * O no armazenado no endereco *raiz TEM NECESSARIAMENTE
 * UM FILHO ARMAZENADO EM (*raiz)->esq OU (exclusivo) (*raiz)->dir.
 * O procedimento deve remover o no armazenado em *raiz e
 * fazer com que *raiz passe a apontar pelo filho do no a
 * ser removido
 */
void removeNoComSomenteUmFilho(NoArvBinaria **raiz);

/*
 * PROCEDIMENTOS DE INSERCAO
 * insere um no com chave igual a k numa arvore binaria
 * de pesquisa dada. O no raiz da arvore dada esta armazenado
 * no endereco *raiz. Assuma que a arvore pode estar vazia
 * nesse caso *raiz==NULL.
 * Devolve o endereco do no recem criado ou o endereco do no
 * que ja contenha chave igual a k.
 */
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
NoArvBinaria *insereArvBinIterativa(NoArvBinaria **raiz, int k);

void removeArvBinRec(NoArvBinaria **raiz, int k);

