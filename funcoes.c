include "funcoes.h"

typedef struct Node {
   int chave;
   int valor;
   struct Node *esq;
   struct Node *dir;
}node;

typedef struct Tree {
	node *raiz;
}tree;

tree criar(){
	tree T = (tree*) malloc(sizeof(tree));
	return(T);
}

int arvore_vazia(tree *T){ 
	if(T != NULL){
		if(T->raiz == NULL) return(0);
	}
	return(1);
}

void inserir(tree *T, int chave, int valor){
	if(T != NULL){
		if(arvore_vazia(T)){
			T->raiz = (node*) malloc(sizeof(node));
			if(T->raiz != NULL){
				T->raiz->chave = chave;
				T->raiz->valor = valor;
				T->raiz->esq = NULL;
				T->raiz->dir = NULL;
			}
		}
		else inserir_no(T->raiz, chave, valor);
	}
}

void inserir_no_novo(node *no, int chave, int valor){
	

void inserir_no(node *no, int chave, int valor){
	if(no != NULL){
		if(no->chave > chave){
			if(no->esq != NULL) inserir_no(no->esq, chave, valor);
			else 
		}
		if(no->chave < chave){
			inserir_no(no->dir, chave, valor);
		}
		if(no->chave == chave){
			no->valor = valor;
		}
	}
			
