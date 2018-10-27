/*
===================================
Funções de nós

Trabalho 2 ICC2


Gabriel Fontes  - 10856803
Leandro Satoshi - 10893103
===================================
*/
#include <stdio.h>
#include <stdlib.h>

#include "nodes.h"

/*
Funções internas.
Tratamos apenas com nós, disso decorre que as funções alteram os endereços
e retornam sempre a nova raiz de tais árvores.
*/
struct Node {
   int chave;
   int valor;
   int nivel;
   struct Node *esq;
   struct Node *dir;
};

/*Cria um novo nó com os dados recebidos, e retorna seu ponteiro*/
node *_no_criar(int chave, int valor) {
	node *no = (node *)malloc(sizeof(node));
	no->chave = chave;
	no->valor = valor;
	no->esq = NULL;
	no->dir = NULL;
	no->nivel = 1;
	
	return(no);
}

/*Recebe dados, cria um nó, e o insere na árvore (nó) dada*/
node *_no_inserir(node *raiz, int chave, int valor) {
	//Caso seja filho de uma folha, vamos criar o nó
	if (raiz == NULL) return(_no_criar(chave, valor));
	
	//Caso o no já exista
	if (chave == raiz->chave)
		raiz->valor = valor;
	
	//Caso seja menor, vamos para a esquerda
	else if (chave < raiz->chave)
		raiz->esq = _no_inserir(raiz->esq, chave, valor);
	
	//Caso seja maior, vamos para a direita
	else if (chave > raiz->chave)
		raiz->dir = _no_inserir(raiz->dir, chave, valor);
	
	//Agora retornamos o endereço. Caso tenha sido adicionado em uma
	//árvore vazia, esse retorno será a nova raiz.
	//Caso contrário, será a própria raiz dada quando a função foi chamada.
	return (raiz);
}

/*Encontra o menor elemento de uma dada arvore, utilizamos isso na remoção*/
node *_no_menor(node *raiz) {
	//Nó auxiliar
	node *atual = raiz;
	
	//Enquanto não chegarmos numa folha, vamos para a esquerda
	while(atual != NULL) atual = atual->esq;
	
	//Retornar essa folha na extrema esquerda
	return (atual);
}

/*Remove um no com dada chave, e retorna a raiz da arvore*/
node *_no_remover(node *raiz, int chave) {
	//Caso alcancemos a folha
	if (raiz == NULL) return (raiz);
	
	//Se a chave for menor que a raiz, ir para a esquerda
	if (chave < raiz->chave) raiz->esq = _no_remover(raiz->esq, chave);
	//Se a chave for maior que a raiz, ir para a direita
	else if (chave > raiz->chave) raiz->dir = _no_remover(raiz->dir, chave);
	
	//Se a chave for encontrada, prosseguir com a remoção
	else {
		//Caso não tenha filho do lado esquerdo
		if (raiz->esq == NULL) {
			//Devolvemos o nó na direita, e removemos a antiga raiz
			node *no = raiz->dir;
			no->nivel--;
			free(raiz);
			return (no);
		}
		
		//Caso não tenha filho do lado direito
		else if (raiz->dir == NULL) {
			//Devolvemos o nó na esquerda, e removemos a antiga raiz
			node *no = raiz->esq;
			no->nivel--;
			free(raiz);
			return (no);
		}
		
		//Caso tenhamos 2 filhos
		//Vamos procurar o menor filho na subarvore direita
		else {
			node *no = _no_menor(raiz->dir);
			
			//Copiamos os conteudos desse nó para a raiz atual
			raiz->chave = no->chave;
			raiz->valor = no->valor;
			
			//Apagar esse nó trocado
			raiz->dir = _no_remover(raiz->dir, no->chave);
		}
	}
	//Retornar a nova raiz
	return (raiz);
}

/*Busca um no com dada chave, e o retorna*/
node *_no_buscar(node *raiz, int chave) {
	if (raiz == NULL) return(NULL);
	//Caso haja filhos, colocamos seus níveis como o do nó atual +1
	if (raiz->esq != NULL) raiz->esq->nivel = raiz->nivel + 1;
	if (raiz->dir != NULL) raiz->dir->nivel = raiz->nivel + 1;
	
	//Caso seja menor do que o nó atual, ir para a esquerda
	if (chave < raiz->chave) return (_no_buscar(raiz->esq, chave));
	//Caso seja maior do que o nó atual, ir para a direitaa
	else if (chave > raiz->chave) return (_no_buscar(raiz->dir, chave));
	//Caso contrário, encontramos
	return (raiz);
}

//Retorna o valor de dado nó
int _no_get_valor(node *no) {
	return(no->valor);
}

//Retorna o nivel de dado nó
int _no_get_nivel(node *no) {
	return(no->nivel);
}