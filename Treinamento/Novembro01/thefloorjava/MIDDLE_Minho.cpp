/*
	MIDDLE.cpp - (PKU) Who's In The Middle?

	Problema do Roteiro 2 - Estruturas de Dados
	
	Link Original do problema: http://poj.org/problem?id=2388
	Link para Dicas da Solução: http://wiki.maratona.dcc.ufmg.br/index.php/PKU_2388

	ATENÇÃO! Pedimos que não veja as dicas da Solução até ter quebrado bastante a cabeça tentando resolver o problema :)

*/
#include <iostream>
#include <algorithm>
#include <vector>

#define all(c) c.begin(),c.end()

using namespace std;

int main() {
	vector<int> cows;
	int n, aux;

	cin >> n;
	for (int i = 0; i < n; ++i)	{
		cin >> aux;
		cows.push_back(aux);
	}

	sort(all(cows));

	cout << cows[(n)/2] << endl;
	
	return 0;
}
