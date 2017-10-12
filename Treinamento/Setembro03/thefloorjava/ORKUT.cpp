/*
	ORKUT.cpp - (SPOJ-BR) ORKUT

	Problema do Roteiro 5 - Algoritmos em Grafos pt.1
	
	Link Original do problema: http://br.spoj.com/problems/ORKUT/
	Link para Dicas da Solução: http://wiki.maratona.dcc.ufmg.br/index.php/ORKUT

	ATENÇÃO! Pedimos que não veja as dicas da Solução até ter quebrado bastante a cabeça tentando resolver o problema :)

*/
#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>

#define all(c) c.begin(),c.end()

using namespace std;

// Graph Adjacency-List Representation
typedef struct Node Node;

struct Node {
	string value;
	vector<Node*> Adj;
};

// Topological Sort
bool noEntries(const vector<Node>& G, string S) {
	for (int i = 0; i < G.size(); ++i) 
		for (int j = 0; j < G[i].Adj.size(); ++i) 
			if(G[i].Adj[j]->value == S) return false;

	return true;
}

int findPos(vector<Node> G, string S) {
	for (int i = 0; i < G.size(); ++i) 
		if(G[i].value == string) return i;
	return -1;
}

vector<Node> topSort(vector<Node> G) {
	vector<Node> L;
	stack<Node> S;
	Node aux;

	for (int i = 0; i < G.size(); ++i) {
		if(noEntries(G, G[i].value)){
			cout << "1. Added " << G[i].value << " to the stack" << endl;
			S.push(G[i]);
		}
	}

	while(!S.empty()) {
		aux = S.top(); S.pop();
		L.push_back(aux);
		cout << "2. Added " << aux.value << " to the list" << endl;

		aux.Adj.clear();
		G.erase(G.begin()+findPos(G, aux.value));

		for (int i = 0; i < G.size(); ++i) {
			if(noEntries(G, G[i].value)){
				cout << "3. Added " << G[i].value << " to the stack" << endl;
				S.push(G[i]);
			}
		}
	}

	for (vector<Node>::iterator i = L.begin(); i != L.end(); ++i) {
		cout << i->value << " ";
	}
	cout << endl;

	return L;
}

int main()
{
	int N, E, idx, idx2;
	string aux;
	Node newNode;
	map<string, int> RS;
	vector<Node> G;

	while(cin >> N && N != 0) {
		G.clear();

		for (int i = 0; i < N; ++i) {
			cin >> aux;
			RS[aux] = i;
			
			newNode.value = aux;
			G.push_back(newNode);
		}

		for (int i = 0; i < N; ++i) {
			cin >> aux >> E;
			idx = RS[aux];

			for (int j = 0; j < E; ++j) {
				cin >> aux;
				G[RS[aux]].Adj.push_back(&G[idx]);
			}
		}
			
		for (int i = 0; i < G.size(); ++i) {
			cout << "# Vertex: " << G[i].value << endl;
			cout << "# Adjacencies: " << endl;
			for (int j = 0; j < G[i].Adj.size(); ++j)
				cout << G[i].Adj[j]->value << " ";
			cout << endl;
		}

		topSort(G);
	}
	
	return 0;
}