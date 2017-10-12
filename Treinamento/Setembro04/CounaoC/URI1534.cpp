/*
	URI1534.cpp - (URI) 1534 - Array 123

	Problema do Roteiro 0 - Primeiros Problemas
	
	Link Original do problema: https://www.urionlinejudge.com.br/judge/pt/problems/view/1534
	Link para Dicas da Solução: http://wiki.maratona.dcc.ufmg.br/index.php/URI1534

	ATENÇÃO! Pedimos que não veja as dicas da Solução até ter quebrado bastante a cabeça tentando resolver o problema :)

*/
#include <iostream>

using namespace std;

int main(){
	int N, **M, i, j;
	while( cin >> N ){
		M = new int*[N];
		for( i=0; i<N; i++ )
			M[i] = new int[N];
		for( i=0; i<N; i++ ){
			for( j=0; j<N; j++ ){
				if( j == (N-1)-i ) M[i][j] = 2;
				else if( j == i ) M[i][j] = 1;
				else M[i][j] = 3;
				cout << M[i][j];
			}
			cout << endl;
		}
		
		for( i=0; i<N; i++ )
			delete M[i];
		delete M;
	}
	
	return 0;
}

