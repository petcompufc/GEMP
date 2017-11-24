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

using namespace std;

int main() {
	int N;
	int Xi;

	map<int,int> mapa;

	cin >> N;

	for(int i = 0; i < N; ++i){
		cin >> Xi;
		mapa[Xi] = mapa[Xi] + 1;

	}

	pair<int,int> ganhador = *mapa.begin();
	for(map<int,int>::iterator it = mapa.begin(); it!=mapa.end(); ++it){

		if(it->second > ganhador.second){
			ganhador = *it;
		}
	}

	cout << ganhador.first << endl;

	
	return 0;
}
