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
	int m, n, **M, i, j, saida = 0, temp = 0;
	cin >> m >> n;
	M = new int*[m];
	for( i=0; i<m; i++ )
		M[i] = new int[n];
	for( i=0; i<m; i++ )
		for( j=0; j<n; j++ )
		   cin >> M[i][j];	
	
	for( i=0; i<m; i++ ){
		for( j=0; j<n; j++ )
			temp += M[i][j];
		if( saida < temp ) saida = temp;
		temp = 0;
	}
	
	for( i=0; i<n; i++ ){
		for( j=0; j<m; j++ )
			temp += M[j][i];
		if( saida < temp ) saida = temp;
		temp = 0;
	}

	cout << saida << endl;
	
	return 0;
}
