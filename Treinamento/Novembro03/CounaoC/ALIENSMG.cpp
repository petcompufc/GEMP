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
#include <string>

using namespace std;

int main() {

	int n;
	string dna;
	set<string> conj;


	for(;;){
		cin >> n;

		if(!n){break;}

		for(int i  = 1; i <= n; ++i){
			cin >> dna;
			sort(dna.begin(),dna.end());
			conj.insert(dna);
		}

		cout << conj.size() << endl;
		conj.clear();
	}	
	return 0;
}
