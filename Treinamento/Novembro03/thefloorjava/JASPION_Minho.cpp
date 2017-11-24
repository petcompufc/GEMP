/*
	JASPION.cpp - (SPOJ-BR) JASPION

	Problema do Roteiro 2 - Estruturas de Dados
	
	Link Original do Problema: http://br.spoj.com/problems/JASPION/
	Link para Dicas da Solução: http://wiki.maratona.dcc.ufmg.br/index.php/JASPION

	ATENÇÃO! Pedimos que não veja as dicas da Solução até ter quebrado bastante a cabeça tentando resolver o problema :)

*/
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	map<string, string> dict;
	int T, M, N, it;
	string aux1, aux2;

	cin >> T;
	for(int i = 0; i < T; i++) {
		dict.clear();
		
		cin >> M >> N;

		dict["o"] = "o";
		for (int j = 0; j < M; ++j) {
			cin >> aux1;
			cin.ignore(256, '\n');
			getline(cin, aux2);
			dict[aux1] = aux2;
		}
		cin.clear();

		for (int i = 0; i < N; ++i) {
			while(cin >> aux1) {
				cout << " " << dict[aux1];
			}
		}
		// it=0;
		// while(it != N) {
		// 	if(cin >> aux1 && aux1 == "o") {
		// 		if(it > 0) cout << endl;
		// 		cout << "o";
		// 		it++;
		// 	}
		// 	else
		// 		cout << " " << dict[aux1];
		// }
		cout << endl;
	}
	
	return 0;
}
