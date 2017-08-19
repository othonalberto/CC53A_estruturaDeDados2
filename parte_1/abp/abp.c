#include <stdlib.h>
#include <stdio.h>
#include "abp.h"

No *aloca_no(int chave) {
    No *novo = (No*)malloc(sizeof(No));
    if (novo == NULL) return NULL;

    novo->chave = chave;
    novo->esq = novo->dir = NULL;

    return novo;
}

No *retorna_pai(No *arvore, int chave) {
    if(arvore == NULL) return NULL;

    while(arvore != NULL) {
        if(chave < arvore->chave) {
            if(arvore->esq == NULL) return arvore;
            else arvore = arvore->esq;
        } else {
            if(arvore->dir == NULL) return arvore;
            else arvore = arvore->dir;
        }
    }
    return NULL;
}

No *insere_no(No **arvore, int chave) {
    No *pai = retorna_pai(*arvore, chave);
    
    if(chave < pai->chave) {
        pai->esq = aloca_no(chave);
        return pai->esq;
    } else {
        pai->dir = aloca_no(chave);
        return pai->dir;
    }
}

void imprime_no(No *no) {
    printf("Mora em: %p\nValor chave: %d\nDireita: %p\nEsquerda: %p\n\n",
            no, no->chave, no->dir, no->esq);
}
