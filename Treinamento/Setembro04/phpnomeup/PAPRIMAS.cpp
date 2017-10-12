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

int teste_palavraPrima(char cadeia[]){
	int i, valor = 0, raiz;
	for (int i = 0; i < 21 && cadeia[i] != '\0'; i++){
		if (cadeia[i]>= 'a' && cadeia[i] <= 'z'){
			valor += cadeia[i] - 'a' + 1;
		}
		else valor+= cadeia[i] - 'A' + 27;
	}
	raiz = (int)sqrt(valor);
	if (valor % 2 == 0 && valor!=2) return 0;
	for (int i = 3; i <= raiz + 1; i+=2){
		if (valor % i == 0){
			return 0;
		}
	}

	return 1;
}

int main(){

	char entrada[21];
	int  saida = 1, raiz;

	while(cin >> entrada){

		saida = teste_palavraPrima(entrada);
		
		if (saida){
			cout << "It is a prime word." << endl;
		}else cout << "It is not a prime word." << endl;

	}


	return 0;
}


