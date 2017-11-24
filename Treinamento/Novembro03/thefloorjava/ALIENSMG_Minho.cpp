/*
	ALIENSMG.cpp - (SPOJ-BR) ALIENSMG

	Problema do Roteiro 2 - Estruturas de Dados
	
	Link Original do Problema: http://br.spoj.com/problems/ALIENSMG/
	Link para Dicas da Solução: http://wiki.maratona.dcc.ufmg.br/index.php/ALIENSMG

	ATENÇÃO! Pedimos que não veja as dicas da Solução até ter quebrado bastante a cabeça tentando resolver o problema :)

*/
#include <iostream>
#include <algorithm>
#include <set>

#define all(c) c.begin(),c.end()

using namespace std;

int main() {
	int N;
	string aux;
	set<string> species;

	while(cin >> N && N != 0) {
		species.clear();

		for (int i = 0; i < N; ++i){
			cin >> aux;
			
			sort(all(aux));
			species.insert(aux);
		}				

		cout << species.size() << endl;
	}

	return 0;
}
