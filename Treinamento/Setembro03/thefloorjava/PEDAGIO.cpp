/*
	PEDAGIO.cpp - (SPOJ-BR) PEDAGIO

	Problema do Roteiro 5 - Algoritmos em Grafos pt.1
	
	Link Original do problema: http://br.spoj.com/problems/PEDAGIO/
	Link para Dicas da Solução: http://wiki.maratona.dcc.ufmg.br/index.php/PEDAGIO

	ATENÇÃO! Pedimos que não veja as dicas da Solução até ter quebrado bastante a cabeça tentando resolver o problema :)

*/
#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

// Graph Adjacency-List Representation
typedef struct Node Node;
typedef struct Graph Graph;

struct Node {
	int value;
	bool visited;
	int d;
	vector<Node*> Adj;
};

struct Graph {
	vector<Node*> V;
};

// Adds a Vertix to the Graph G
void createGraph(Graph* G, int size) {
	for (int i = 0; i < size; ++i) {
		Node* newNode = new Node; 
		newNode->value = i+1;
		
		G->V.push_back(newNode);
	}
}

// Adds a Edge to the Graph G
// O --> Origin, D --> Destination
void addEdge(Graph* G, int O, int D) {
	G->V[O-1]->Adj.push_back(G->V[D-1]);
	G->V[D-1]->Adj.push_back(G->V[O-1]);
}

set<int> BFS(Graph* G, int S, int P) {
	for (int i = 0; i < G->V.size(); ++i)
		G->V[i]->visited = false;
	
	G->V[S-1]->visited = true;
	G->V[S-1]->d = 0;

	queue<Node*> Q;
	set<int> cities;

	Q.push(G->V[S-1]);
	while(!Q.empty()) {

		Node* u = Q.front(); Q.pop();
		if(u->d > P) return cities;

		for (int i = 0; i < u->Adj.size(); ++i)	{
			if(!u->Adj[i]->visited) {
				u->Adj[i]->visited = true;
				u->Adj[i]->d = u->d + 1;

				Q.push(u->Adj[i]);
				if(u->Adj[i]->d <= P) cities.insert(u->Adj[i]->value);
			}
		}
	}
}

// ---

int main()
{
	Graph* G;
	int C, E, L, P, test = 1;
	int auxO, auxD;
	set<int> cities;

	while(cin >> C >> E >> L >> P && (C+E+L+P) != 0) {
		G = new Graph;
		createGraph(G, C);

		for (int i = 0; i < E; ++i) {
			cin >> auxO >> auxD;
			addEdge(G, auxO, auxD);
		}

		cities = BFS(G, L, P);

		cout << "Teste " << test << endl;
		set<int>::iterator it;
		for(it = cities.begin(); it != cities.end(); ++it) 
			cout << *it << " ";
		
		cout << endl << endl;

		delete G; test++;
	}

	return 0;
}