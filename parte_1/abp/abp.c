#include <stdlib.h>
#include <stdio.h>
#include "abp.h"

No *aloca_no(int chave) {
    No *novo = (No*)malloc(sizeof(No));
    if (novo == NULL)
        return NULL;

    novo->chave = chave;
    novo->esq = novo->dir = NULL;

    return novo;
}

void imprime_no (No *no) {
    printf("Mora em: %p\nValor chave: %d\nDireita: %p\nEsquerda: %p\n\n",
            no, no->chave, no->dir, no->esq);
}
