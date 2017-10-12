/*
	DUENDE.cpp - (SPOJ-BR) DUENDE

	Problema do Roteiro 5 - Algoritmos em Grafos pt.1
	
	Link Original do problema: http://br.spoj.com/problems/DUENDE/
	Link para Dicas da Solução: http://wiki.maratona.dcc.ufmg.br/index.php/DUENDE

	ATENÇÃO! Pedimos que não veja as dicas da Solução até ter quebrado bastante a cabeça tentando resolver o problema :)

*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int main()
{
	int N, M, x, y, A;
	int S[2];

	int G[10][10];
	int D[10][10];
	bool V[10][10];

	pair<int,int> node;
	queue< pair<int,int> > Q;
	vector< pair<int, int> > exits;

	cin >> N >> M;

	for (int i = 0; i < N; ++i){
		for (int j = 0; j < M; ++j){
			cin >> G[i][j];
	
			V[i][j] = 0;
			D[i][j] = N*M+1;

			if(G[i][j] == 3) {
				V[i][j] = 1;
				D[i][j] = 0;
				S[0] = i;
				S[1] = j;
			}
			else if(G[i][j] == 0)
				exits.push_back(make_pair(i, j));
		}
	}

	// Breadth-First Search
	Q.push(make_pair(S[0], S[1]));
	while(!Q.empty()) {
		node = Q.front(); Q.pop();
		x = node.first;
		y = node.second;

		// Esquerda
		if(x-1 >= 0 && !V[x-1][y] && G[x-1][y] != 2) {
			V[x-1][y] = 1;
			D[x-1][y] = D[x][y] + 1;
			Q.push(make_pair(x-1, y));
		}
		// Cima
		if(y-1 >= 0 && !V[x][y-1] && G[x][y-1] != 2) {
			V[x][y-1] = 1;
			D[x][y-1] = D[x][y] + 1;
			Q.push(make_pair(x, y-1));
		}
		// Direita
		if(x+1 < N && !V[x+1][y] && G[x+1][y] != 2) {
			V[x+1][y] = 1;
			D[x+1][y] = D[x][y] + 1;
			Q.push(make_pair(x+1, y));
		}
		// Baixo
		if(y+1 < M && !V[x][y+1] && G[x][y+1] != 2) {
			V[x][y+1] = 1;
			D[x][y+1] = D[x][y] + 1;
			Q.push(make_pair(x, y+1));
		}
	}

	// Verifica a distância da saída
	A = N*M+1;

	for (int i = 0; i < exits.size(); ++i) {
		node = exits[i];
		x = node.first;
		y = node.second;

		if(D[x][y] < A) A = D[x][y];
	}

	cout << A << endl;

	return 0;
}