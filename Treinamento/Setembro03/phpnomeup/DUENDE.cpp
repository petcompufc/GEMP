/*
	DUENDE.cpp - (SPOJ-BR) DUENDE

	Problema do Roteiro 5 - Algoritmos em Grafos pt.1
	
	Link Original do problema: http://br.spoj.com/problems/DUENDE/
	Link para Dicas da Solução: http://wiki.maratona.dcc.ufmg.br/index.php/DUENDE

	ATENÇÃO! Pedimos que não veja as dicas da Solução até ter quebrado bastante a cabeça tentando resolver o problema :)

*/
#include <cstdio>
#include <cstdlib>

using namespace std;

int caverna[20][20];
int passos[20][20];

int duende(int x,int y,int custo){
	if (caverna[x][y]==2)return 0;
	
	if (custo >= passos[x][y])return 0;
	
	passos[x][y] = custo;
	
	if (caverna[x][y]==0)return 0;
	
	duende(x+1,y,custo+1);
	duende(x-1,y,custo+1);
	duende(x,y-1,custo+1);
	duende(x,y+1,custo+1);
	
	return 0;
}
	


int main (){
	for (int i=0;i<20;i++){
		for (int j=0;j<20;j++){
			passos[i][j]=999999999;
			caverna[i][j]=2;
		}
	}
	
	
	int n,m;	
	scanf ("%d %d",&n,&m);
	
	int ini_i,ini_j;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			scanf ("%d",&caverna[i][j]);
			if (caverna[i][j]==3){
				ini_i = i;
				ini_j = j;
			}
		}
	}
	
	duende (ini_i,ini_j,0);
	
	int resposta = 999999999;
	
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (caverna[i][j]==0 && passos[i][j]<resposta){
				resposta = passos[i][j];
			}
		}
	}
	
	printf ("%d\n",resposta);
	
	return 0;
}