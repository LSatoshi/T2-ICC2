/*
===================================
Funções de árvores

Trabalho 2 ICC2


Gabriel Fontes  - 10856803
Leandro Satoshi - 10893103
===================================
*/
#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"

#include "trees.h"

/*
Funções externas.
Criamos uma estrutura para armazenar um nó raiz,
assim evitando que o usuário tenha que reatribuir
suas variáveis quando manipuladas.
*/
struct Tree {
	int tam;
	node *r;
};

/*Aloca uma nova árvore, e retorna seu endereço*/
tree *criar_arvore() {
	tree *T = (tree *)malloc(sizeof(tree));
	T->r = NULL;
	T->tam = 0;
	
	return (T);
}

/*Insere um elemento na árvore dada*/
void inserir_arvore(tree *T, int chave, int valor) {
	if (T != NULL) {
		T->r = _no_inserir(T->r, chave, valor);
		T->tam++;
	}
}

/*Remove um elemento dado de uma árvore dada*/
void remover_arvore(tree *T, int chave) {
	if (T != NULL && T->tam > 0) {
		T->r = _no_remover(T->r, chave);
		T->tam--;
	}
}

/*Imprime na tela o valor e nível de um nó com chave dada*/
void buscar_arvore(tree *T, int chave) {
	node *no = _no_buscar(T->r, chave);
	if (no == NULL)
		printf("ERRO: Nao encontrado!\n");
	else
		printf("Valor: %d, Nivel: %d", _no_get_valor(no), _no_get_nivel(no));
}