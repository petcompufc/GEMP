/*
	MIDDLE.cpp - (PKU) Who's In The Middle?

	Problema do Roteiro 2 - Estruturas de Dados
	
	Link Original do problema: http://poj.org/problem?id=2388
	Link para Dicas da Solução: http://wiki.maratona.dcc.ufmg.br/index.php/PKU_2388

	ATENÇÃO! Pedimos que não veja as dicas da Solução até ter quebrado bastante a cabeça tentando resolver o problema :)

*/
#include <iostream>
#include <algorithm> //sort
#include <vector> // vector

using namespace std;

int main() {

	int N, i, middle, aux;
	vector<int> v;

	cin >> N;
	middle = N/2;
	for (i = 0; i<N; i++){
		cin >> aux;
		v.push_back(aux);
	}
	sort(v.begin(), v.end());
	cout << v[middle] << '\n';
	
	return 0;
}
