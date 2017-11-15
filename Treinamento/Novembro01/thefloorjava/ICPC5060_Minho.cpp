/*
	ICPC5060.cpp - (ICPC) Live Archive 5060

	Problema do Roteiro 2 - Estruturas de Dados
	
	Link Original do problema (Cliquem no símbolo do "PDF" no lado superior direito): 
	https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3061

	Link para Dicas da Solução: http://wiki.maratona.dcc.ufmg.br/index.php/Live_Archive_5060

	ATENÇÃO! Pedimos que não veja as dicas da Solução até ter quebrado bastante a cabeça tentando resolver o problema :)

*/
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

typedef struct wrestler Wrestler;

struct wrestler {
	int idx, Po, P;
	vector<int> wins;
};

int main() {
	queue<Wrestler> P;
	Wrestler aux, a1, a2;
	int t, n, k;

	cin >> t;

	for (int i = 0; i < t; ++i) {
		cin >> n >> k;

		for (int j = 0; j < pow(2,n); ++j){
			aux.idx = j+1;
			cin >> aux.Po; aux.P = aux.Po; 
			P.push(aux);
		}

		while(P.size() > 1) {
			a1 = P.front(); P.pop();
			a2 = P.front(); P.pop();

			if(a1.P >= a2.P) {
				a1.P = (a1.P - a2.P + k > a1.Po) ? a1.Po : (a1.P - a2.P + k);
				a1.wins.push_back(a2.idx);
				P.push(a1);
			} else {
				a2.P = (a2.P - a1.P + k > a2.Po) ? a2.Po : (a2.P - a1.P + k);
				a2.wins.push_back(a1.idx);
				P.push(a2);
			}
		}

		cout << P.front().idx << endl;
		for (int k = 0; k < P.front().wins.size(); ++k)
			cout << P.front().wins[k] << " ";
		cout << endl;
		P.pop();
	}


	return 0;
}
