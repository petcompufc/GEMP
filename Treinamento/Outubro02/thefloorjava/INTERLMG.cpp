/*
	INTERLMG.cpp - (SPOJ-BR) INTERLMG

	Problema do Roteiro 6 - Algoritmos em Grafos
	
	Link Original do problema: http://br.spoj.com/problems/INTERLMG/
	Link para Dicas da Solução: http://wiki.maratona.dcc.ufmg.br/index.php/INTERLMG

	ATENÇÃO! Pedimos que não veja as dicas da Solução até ter quebrado bastante a cabeça tentando resolver o problema :)

*/
#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

float eucDist(pair<float,float> po1, pair<float,float> po2) {
	return sqrt(pow(po1.first-po2.first, 2) + pow(po1.second-po2.second, 2) );
}

int main() {
	int N;
	float aux1, aux2;
	vector< pair<float, float> > cidade;

	while(cin >> N && N != 0) {
		cidade.clear();

		for (int i = 0; i < N; ++i) {
			cin >> aux1 >> aux2;
			cidade.push_back(make_pair(aux1, aux2));
		}

		for (int i = 1; i < N; ++i)	{
			cout << eucDist(cidade[i], cidade[i-1]) << endl;
		}
	}
	
	return 0;
}
