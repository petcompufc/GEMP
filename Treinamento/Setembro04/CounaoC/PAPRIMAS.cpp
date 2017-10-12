/*
	PAPRIMAS.cpp - (SPOJ-BR) PAPRIMAS

	Problema do Roteiro 0 - Primeiros Problemas
	
	Link Original do problema: http://br.spoj.com/problems/PAPRIMAS/
	Link para Dicas da Solução: http://wiki.maratona.dcc.ufmg.br/index.php/PAPRIMAS

	ATENÇÃO! Pedimos que não veja as dicas da Solução até ter quebrado bastante a cabeça tentando resolver o problema :)

*/
#include <iostream>
#include <cmath>

using namespace std;

int test_primo( long unsigned int x ){
	int divisor, limite;
	if( x%2 == 0 && x != 2) return 0;
	limite = sqrt(x)/1 + 1;
	for( divisor = 3; divisor < limite; divisor +=2 ){
		if( x%divisor == 0 )
			return 0;
	}
	return 1;
}

int main(){
	char entrada[21], i;
	long unsigned int N = 0;
	while( cin >> entrada ){        
		for( i=0; entrada[i] != '\0'; i++ ){
			if( entrada[i] >= 'a' && entrada[i] <= 'z' )
				entrada[i] -= 'a' - 1;
			else if ( entrada[i] >= 'A' && entrada[i] <= 'Z' )
				entrada[i] -= 'A' - 27;
			else return -1;
			N += entrada[i];
		}
		if(test_primo(N)) cout << "It is a prime word." << endl;
		else cout << "It is not a prime word." << endl;
		N = 0;
	}

	return 0;
}
