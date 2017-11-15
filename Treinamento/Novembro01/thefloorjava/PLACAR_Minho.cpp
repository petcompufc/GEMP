/*
	PLACAR.cpp - (SPOJ-BR) PLACAR

	Problema do Roteiro 2 - Estruturas de Dados
	
	Link Original do problema: http://br.spoj.com/problems/PLACAR/
	Link para Dicas da Solução: http://wiki.maratona.dcc.ufmg.br/index.php/PLACAR

	ATENÇÃO! Pedimos que não veja as dicas da Solução até ter quebrado bastante a cabeça tentando resolver o problema :)

*/
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

#define all(c) c.begin(),c.end()

using namespace std;

bool comp(const pair<string, short> &a1, const pair<string, short> &a2) {
	return (a1.second >= a2.second);
}

int main() {
	vector< pair<string, short> > A;
	string aux1;
	short aux2;
	int n, it=1;

	while(cin >> n) {
		A.clear();
		for (int i = 0; i < n; ++i) {
			cin >> aux1 >> aux2;
			A.push_back(make_pair(aux1, aux2));
		}

		sort(all(A), comp);

		cout << "Instancia " << it << endl;
		cout << A[n-1].first << endl;
		cout << endl; it++;
	}

	return 0;
}
