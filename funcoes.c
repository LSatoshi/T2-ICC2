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

tree criar(){ // aloca espaço para inicio da arvore e devolve ponteiro
	tree T = (tree*) malloc(sizeof(tree));
	return(T);
}

int arvore_vazia(tree *T){  //verifica se a arvore existe e esta vazia
	if(T != NULL){
		if(T->raiz == NULL) return(0);
	}
	return(1);
}

void inserir(tree *T, int chave, int valor){ //funcao acessada pelo usuario, insere elemento na arvore
	if(T != NULL){
		if(arvore_vazia(T)){//se a arvore estiver vazia, aloca espaco
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

void inserir_no_novo(node *no, int chave, int valor){//funcao para inserir um no novo, alocando espaco
	node *novo;
	novo = (node*) malloc(sizeof(node));
	if(novo != NULL){
		novo->chave = chave;
		novo->valor = valor;
		novo->esq = NULL;
		novo->dir = NULL;
	}
	no = *novo;
}
	

void inserir_no(node *no, int chave, int valor){//funcao de apoio para inserir no na posicao correta, chamada recursivamente apenas no interior da funcoes.c
	if(no->chave > chave){
		if(no->esq != NULL) inserir_no(no->esq, chave, valor);
		else inserir_no_novo(no->esq, chave, valor);
	}
	if(no->chave < chave){
		if(no->esq != NULL) inserir_no(no->dir, chave, valor);
		else inserir_no_novo(no->dir, chave, valor);
	}
	if(no->chave == chave){
		no->valor = valor;
	}
}
			
