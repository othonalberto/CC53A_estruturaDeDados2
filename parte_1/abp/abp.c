#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "abp.h"
#include "outras.h"

No *aloca_no(int chave) {
    No *novo = (No*)malloc(sizeof(No));
    if (novo == NULL) return NULL;

    novo->chave = chave;
    novo->esq = novo->dir = NULL;

    return novo;
}

No *insere_rec(No **arvore, int chave) {
    assert(arvore); 
 
    if (*arvore == NULL) {
        *arvore = aloca_no(chave);
        return *arvore;
    }

    if (chave < (*arvore)->chave)
        return insere_rec(&((*arvore)->esq), chave);
    else
        if (chave > (*arvore)->chave)
            return insere_rec(&((*arvore)->dir), chave);
        else
            return NULL; //valor chave já existe 
}

No **busca_no(No **arvore, int chave) {
    if (*arvore == NULL) return NULL;

    if (chave == (*arvore)->chave) return arvore;
 
    if (chave < (*arvore)->chave)
        return busca_no(&((*arvore)->esq), chave);
    else
        return busca_no(&((*arvore)->dir), chave);

}

void remove_no(No **arvore, int chave) {
    No **pp = busca_no(arvore, chave);
    No *filho = NULL;

    //Caso 1: nó folha
    if ((*pp)->esq == NULL && (*pp)->dir == NULL) {
        free(*pp);
        *pp = NULL;
        return;
    }

    //Caso 2: apenas um filho
    if (((*pp)->esq == NULL) != ((*pp)->dir == NULL)) {
        filho = ((*pp)->esq == NULL) ? (*pp)->dir : (*pp)->esq;

        free(*pp);
        *pp = filho;
        return;
    }

    //Caso 3: dois filhos
    if ((*pp)->esq && (*pp)->dir) {
        No **substituto = busca_endereco_ponteiro_menor(&((*arvore)->dir));
        substitui_dados(pp, substituto);
        remove_no(substituto, (*substituto)->chave); //entrará no caso 2, e será 0(1)
        return;
    }
}

void imprime_no(No *no) {
    printf("Mora em: %p\nValor chave: %d\nEsquerda: %p\nDireita: %p\n\n", no, no->chave, no->esq, no->dir);
}

void pre_ordem(No *raiz) {
    if (raiz == NULL) return;

    printf("%d\n", raiz->chave);
    pre_ordem(raiz->esq);
    pre_ordem(raiz->dir);
}
