/*
===================================
Header de trees.c

Trabalho 2 ICC2


Gabriel Fontes  - 10856803
Leandro Satoshi - 10893103
===================================
*/

#ifndef trees_H_
#define trees_H_

typedef struct Tree tree;
tree *criar_arvore();
void inserir_arvore(tree *T, int chave, int valor);
void remover_arvore(tree *T, int chave);
void buscar_arvore(tree *T, int chave);

#endif