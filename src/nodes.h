/*
===================================
Header de nodes.c

Trabalho 2 ICC2


Gabriel Fontes  - 10856803
Leandro Satoshi - 10893103
===================================
*/

#ifndef nodes_H_
#define nodes_H_

typedef struct Node node;
node *_no_criar(int chave, int valor);
node *_no_inserir(node *raiz, int chave, int valor);
node *_no_menor(node *raiz);
node *_no_remover(node* raiz, int chave);
node *_no_buscar(node* raiz, int chave);
int _no_get_valor(node *no);
int _no_get_nivel(node *no);

#endif