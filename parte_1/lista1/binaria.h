#ifndef ARVBINARIA_H
#define ARVBINARIA_H

#include <stdlib.h>

struct NoArvBinaria
{
  int chave;
  struct NoArvBinaria * esq;
  struct NoArvBinaria * dir;
};

typedef struct NoArvBinaria NoArvBinaria;
NoArvBinaria *insere_rec(NoArvBinaria **arvore, int chave); 


/*
 * PROCEDIMENTOS DE BUSCA CLASSICOS
 * devolve o endereco do no cujo valor chave eh k
 * ou NULL caso tal no nao exista na arvore enraizada
 * por raiz.
 */
NoArvBinaria *buscaArvBinRec(NoArvBinaria *raiz, int k);
NoArvBinaria *buscaArvBinIterativa(NoArvBinaria *raiz, int k);

/*
 * PROCEDIMENTOS DE BUSCA DO MENOR/MAIOR
 * 1) devolve o endereco do no cujo valor chave eh o
 *    menor da arvore dada ou NULL caso a arvore seja vazia.
 * 2) devolve o endereco do no cujo valor chave eh o
 *    maior da arvore dada ou NULL caso a arvore seja vazia.
 */
NoArvBinaria *buscaEnderecoDoMenor(NoArvBinaria *raiz); /*1*/
NoArvBinaria *buscaEnderecoDoMaior(NoArvBinaria *raiz); /*2*/


/*
 * PROCEDIMENTO DE BUSCA DO ENDERECO DO PONTEIRO DO NO k
 * devolve o endereco onde está armazenado o endereco do no 
 * cujo valor chave eh k ou NULL caso tal no nao exista. O 
 * no raiz da arvore dada esta armazenado no endereco *raiz.
 * Assuma que a arvore pode estar vazia, nesse caso *raiz==NULL.
 * i.e.: Para arvores nao vazias, a funcao deve devolver um 
 * ponteiro x tal que a seguinte  condicao seja satisfeita: 
 * (*x)->chave == k
 */
NoArvBinaria **buscaEnderecoDoPonteiro(NoArvBinaria **raiz, int k);


/*
 * PROCEDIMENTOS DE BUSCA DO ENDERECO DO PONTEIRO DO MENOR/MAIOR
 * 1) devolve o endereco do ponteiro para o no cujo valor chave eh o
 *    menor da arvore dada ou NULL caso a arvore seja vazia.
 *    i.e.: Para arvores nao nulas a funcao deve devolver um ponteiro x 
            tal que (*x)->chave eh o menor valor chave de toda a arvore dada
 * 2) devolve o endereco do ponteiro para o no cujo valor chave eh o
 *    maior da arvore dada ou NULL caso a arvore seja vazia.
 *    i.e.: Para arvores nao nulas a funcao deve devolver um ponteiro x 
 *          tal que (*x)->chave eh o maior valor chave de toda a arvore dada
 * O parametro de entrada raiz eh o endereco do ponteiro para o raiz
 * da arvore.
 */
NoArvBinaria **buscaEnderecoDoPonteiroDoMenor(NoArvBinaria **raiz); /*1*/
NoArvBinaria **buscaEnderecoDoPonteiroDoMaior(NoArvBinaria **raiz); /*2*/

/*
 * Assume que *folha aponta para um no folha
 * de uma arvore binaria de pesquisa qualquer.
 * O procedimento deve remover tal no.
 */
void removeFolha(NoArvBinaria **folha);

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
NoArvBinaria *insereArvBinRec(NoArvBinaria **raiz, int k);
NoArvBinaria *insereArvBinIterativa(NoArvBinaria **raiz, int k);

void removeArvBinRec(NoArvBinaria **raiz, int k);

#endif
