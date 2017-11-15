/*
	TENTA.cpp - (SPOJ-BR) TENTA

	Problema do Roteiro 2 - Estruturas de Dados
	
	Link Original do problema: http://br.spoj.com/problems/TENTA/
	Link para Dicas da Solução: http://wiki.maratona.dcc.ufmg.br/index.php/TENTA

	ATENÇÃO! Pedimos que não veja as dicas da Solução até ter quebrado bastante a cabeça tentando resolver o problema :)

*/
#include <iostream>
#include <vector>
#include <algorithm>
 
#define all(c) c.begin(),c.end()
 
using namespace std;
 
void printPermutes(vector<int> &cards) {
	sort(all(cards));
 
	do {
		for(int i = 0; i < cards.size(); i++)
			cout << cards[i] << ' ';
		cout << endl;
	} while(next_permutation(all(cards)));
 
	cout << endl;
}
 
int main()
{
	int n;
	vector<int> cards;
 
	while(cin >> n && n != 0) {
		cards.clear(); cards.resize(n, 0);
		for (int i = 0; i < n; ++i)
			cin >> cards[i];
 
		printPermutes(cards);
	}
 
	return 0;
} 