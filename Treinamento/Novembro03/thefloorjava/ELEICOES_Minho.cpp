/*
	ELEICOES.cpp - (SPOJ-BR) ELEICOES

	Problema do Roteiro 2 - Estruturas de Dados
	
	Link Original do Problema: http://br.spoj.com/problems/ELEICOES/
	Link para Dicas da Solução: http://wiki.maratona.dcc.ufmg.br/index.php/ELEICOES

	ATENÇÃO! Pedimos que não veja as dicas da Solução até ter quebrado bastante a cabeça tentando resolver o problema :)

*/
#include <iostream>
#include <algorithm>
#include <map>

#define all(c) c.begin(),c.end()

using namespace std;

int main() {
	int N, aux;
	map<int,int> votos;

	cin >> N;

	for (int i = 0; i < N; ++i)	{
		cin >> aux;
		if(votos.count(aux) == 0)
			votos[aux] = 1;
		else
			votos[aux] += 1;
	}

	auto winner = std::max_element(all(votos),
		[](const pair<int, int>& p1, const pair<int, int>& p2) {
		        return p1.second < p2.second; 
		    }
        );


	cout << winner->first << endl;
	
	return 0;
}
