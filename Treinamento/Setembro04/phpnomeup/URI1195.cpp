/*
	URI1195.cpp - (URI) 1195 - Binary Search Tree

	Problema Off-Roteiro
	
	Link Original do problema: https://www.urionlinejudge.com.br/judge/en/problems/view/1195
	
	ATENÇÃO! Pedimos que não veja as dicas da Solução até ter quebrado bastante a cabeça tentando resolver o problema :)

*/
#include <stdio.h>
#include <stdlib.h>

struct node{
	int valor;
	node* esq;
	node* dir;
};

typedef struct node no;

no* raiz; //A partir daqui, a árvore binária será construida

void insere(int valor){
	no* novo;
	novo = (no*) malloc(sizeof(no));
	novo->valor = valor;
	novo->esq = NULL;
	novo->dir = NULL;

	if(raiz == NULL){
		raiz = novo;
	}else{
		no* atual = raiz;
		while(1){
			if(atual->valor > valor){
				if(atual->esq == NULL){
					atual->esq = novo;
					break;
				}else{
					atual = atual->esq;
				}
			}else{
				if(atual->dir == NULL){
					atual->dir = novo;
					break;
				}else{
					atual = atual->dir;
				}
			}
		}


	}
}

void prefixa(no* atual){
	if(atual != NULL){
		printf(" %d",atual->valor);
		prefixa(atual->esq);
		prefixa(atual->dir);
	}
}

void infixa(no* atual){
	if(atual != NULL){
		infixa(atual->esq);
		printf(" %d",atual->valor);
		infixa(atual->dir);
	}
}

void posfixa(no* atual){
	if(atual != NULL){
		posfixa(atual->esq);
		posfixa(atual->dir);
		printf(" %d",atual->valor);
	}
}


int main(){
	int c,n;

	raiz = NULL;
	scanf("%d",&c);

	int caso = 0;
	while (caso < c){
		caso++;

		scanf("%d",&n);

		int valor;
		for(int i=0;i<n;i++){
			scanf("%d",&valor);
			insere(valor);
		}

		printf("Case %d:\n",caso);

		printf("Pre.:");
		prefixa(raiz);
		printf("\nIn..:");
		infixa(raiz);
		printf("\nPost:");
		posfixa(raiz);
		printf("\n\n");


		free(raiz);
		raiz = NULL;
	}

	return 0;
}