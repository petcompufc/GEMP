/*
	MINHOCA.cpp - (SPOJ-BR) MINHOCA

	Problema do Roteiro 0 - Primeiros Problemas
	
	Link Original do problema: http://br.spoj.com/problems/MINHOCA/
	Link para Dicas da Solução: http://wiki.maratona.dcc.ufmg.br/index.php/MINHOCA

	ATENÇÃO! Pedimos que não veja as dicas da Solução até ter quebrado bastante a cabeça tentando resolver o problema :)

*/
#include <iostream>

using namespace std;

int main(){	
	int n,m, soma = 0, maximo = 0;
	cin >> n >> m;
	int A[n][m];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> A[i][j]; 
			soma += A[i][j];
		}
		if(soma > maximo){
			maximo = soma;
		}
		soma = 0;
	}
	for(int j = 0; j < m; ++j){
		for(int i = 0; i < n; ++i){
			soma += A[i][j];
		}
		if(soma > maximo){
			maximo = soma;
		}
		soma = 0;
	}
	cout << maximo;
	return 0;
}