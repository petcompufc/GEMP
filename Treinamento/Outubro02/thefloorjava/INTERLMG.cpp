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
#include <limits.h>

#define INF INT_MAX

using namespace std;

float eucDist(pair<float,float> po1, pair<float,float> po2) {
	return sqrt(pow(po1.first-po2.first, 2) + pow(po1.second-po2.second, 2) );
}

void printGraph(const vector< vector<float> > &graph) {
	for (int i = 0; i < graph.size(); ++i) {
		for (int j = 0; j < graph[i].size(); ++j)
				cout << graph[i][j] << "\t";
		cout << endl;
	}

}

int minKey(float key[], int N, bool mstSet[]) {
	int min = INF, min_index;

	for (int i = 0; i < N; ++i)
		if(mstSet[i] == false && key[i] < min){
			min = key[i]; min_index = i;
		}

	return min_index;
}

void printMST(int parent[], const vector< vector<float> > &graph)
{
   cout << "Edge   Weight" << endl;
   for (int i = 1; i < graph.size(); i++)
      cout << parent[i] << " - " << i << "    " << graph[i][parent[i]] << endl;
}

void primMST(const vector< vector<float> > &graph) {
     int parent[graph.size()];
     float key[graph.size()];
     bool mstSet[graph.size()];
 
     for (int i = 0; i < graph.size(); i++)
        key[i] = INF, mstSet[i] = false;
 
     key[0] = 0;
     parent[0] = -1;
 
     for (int count = 0; count < graph.size()-1; count++) {
        int u = minKey(key, graph.size(), mstSet);
 
        mstSet[u] = true;
 
        for (int v = 0; v < graph.size(); v++)
          if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }
 
     printMST(parent, graph);
}

int main() {
	int N;
	float aux1, aux2;
	vector< pair<float, float> > cidade;
	vector< vector <float> > D;

	while(cin >> N && N != 0) {
		cidade.clear();
		
		D.resize(N);
		for (int i = 0; i < N; ++i)
			D[i].resize(N);

		for (int i = 0; i < N; ++i) {
			cin >> aux1 >> aux2;
			cidade.push_back(make_pair(aux1, aux2));
		}

		for (int i = 0; i < N; i++)	
			for (int j = i+1; j < N; j++) 
				D[i][j] = D[j][i] = eucDist(cidade[i], cidade[j]);

		printGraph(D);

		primMST(D);

	}
	
	return 0;
}
