#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "abp.h"

No *aloca_no(int chave) {
    No *novo = (No*)malloc(sizeof(No));
    if (novo == NULL) return NULL;

    novo->chave = chave;
    novo->esq = novo->dir = NULL;

    return novo;
}

No **retorna_campo(No *arvore, int chave) {
    if(arvore == NULL) return NULL;

    if(chave < arvore->chave) {
        if(arvore->esq == NULL)
            return &(arvore->esq);
        else
            return retorna_campo(arvore->esq, chave);
    } else {
        if(arvore->dir == NULL)
            return &(arvore->dir);
        else
            return retorna_campo(arvore->dir, chave);
    }
}

No *insere_no(No **arvore, int chave) {
    No **campo = retorna_campo(*arvore, chave);
    
    if(campo == NULL) {
        *arvore = aloca_no(chave);
        return *arvore;
    }

    *campo = aloca_no(chave);
    return *campo;
}

No *insere_rec(No **arvore, int chave) {
    assert(arvore); 
    
    if(*arvore == NULL) {
        *arvore = aloca_no(chave);
        return *arvore;
    }

    if(chave < (*arvore)->chave) 
        return insere_rec(&((*arvore)->esq), chave);
    else
        return insere_rec(&((*arvore)->dir), chave);
}

No *busca_no(No *arvore, int chave) {
    if(arvore == NULL) return NULL;

    if(chave == arvore->chave) return arvore;
 
    if(chave < arvore->chave)
        return busca_no(arvore->esq, chave);
    else
        return busca_no(arvore->dir, chave);

}

void imprime_no(No *no) {
    printf("Mora em: %p\nValor chave: %d\nDireita: %p\nEsquerda: %p\n\n", no, no->chave, no->dir, no->esq);
}
