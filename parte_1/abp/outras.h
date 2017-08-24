#ifndef OUTRAS_ABP
#define OUTRAS_ABP

#include "abp.h"

// struct No está em abp.h
/*
 * typedef struct No {
 *     int chave;
 *     struct No *esq;
 *     struct No *dir;
 * } No;
*/

// AQUI ESTAO OUTRAS FUNCOES PARA ESTUDO

// procura o campo correto para a inserção de um novo nó
No **retorna_campo(No *arvore, int chave);

// utilizando aloca_no e retorna_pai, insere um novo nó na arvore
No *insere_no(No **arvore, int chave);

#endif