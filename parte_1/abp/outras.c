#include <stdlib.h>
#include <assert.h>
#include "outras.h"

No **retorna_campo(No *arvore, int chave) {
    while (arvore != NULL) {
        if (chave < arvore->chave) {
            if (arvore->esq == NULL)
                return &(arvore->esq);
            else
                arvore = arvore->esq;
        } else {
            if (arvore->dir == NULL)
                return &(arvore->dir);
            else
                arvore = arvore->dir;
        }
    } 

     return NULL;
}

No *insere_no(No **arvore, int chave) {
    No **campo = retorna_campo(*arvore, chave);
 
    if (campo == NULL) { //isso só irá acontecer quando a árvore estiver vazia.
        *arvore = aloca_no(chave);
        return *arvore;
    }

    *campo = aloca_no(chave);
    return *campo;
}

void substitui_dados(No **p1, No **p2) {
    (*p1)->chave = (*p2)->chave;
}

No **busca_endereco_ponteiro_menor(No **arvore) {
    assert(arvore);

    if (*arvore == NULL) return NULL;

    if ((*arvore)->esq == NULL)
        return arvore;
    else
        return busca_endereco_ponteiro_menor(&((*arvore)->esq));
}

No **busca_endereco_ponteiro_maior(No **arvore) {
    assert(arvore);

    if (*arvore == NULL) return NULL;

    if ((*arvore)->dir == NULL)
        return arvore;
    else
        return busca_endereco_ponteiro_maior(&((*arvore)->dir));
}
