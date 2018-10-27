/*
===================================
Main

Trabalho 2 ICC2


Gabriel Fontes  - 10856803
Leandro Satoshi - 10893103
===================================
*/
#include <stdio.h>
#include <stdlib.h>
#include "trees.h"

int main() {
	tree *T = criar_arvore();
	int escolha = 0;
	int chave, valor;
	
	while (1) {
		printf("\n\n");
		printf("Digite a operacao desejada: \n");
		printf("1 - Adicionar elemento\n");
		printf("2 - Remover elemento\n");
		printf("3 - Buscar elemento\n");
		printf("4 - Sair\n");
		printf("\n>");
		scanf("%d", &escolha);
		printf("\n\n");
		
		switch(escolha) {
			case 1:
				printf("Chave: ");
				scanf("%d", &chave);
				printf("Valor: ");
				scanf("%d", &valor);
				inserir_arvore(T, chave, valor);
				break;
			case 2:
				printf("Chave: ");
				scanf("%d", &chave);
				remover_arvore(T, chave);
				break;
			case 3:
				printf("Chave: ");
				scanf("%d", &chave);
				buscar_arvore(T, chave);
				break;
			case 4:
				return(1);
		}
	}
	
	return(1);
}