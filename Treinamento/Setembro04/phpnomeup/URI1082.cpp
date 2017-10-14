/*
	URI1082.cpp - (URI) 1082 - Connected Components

	Problema Off-Roteiro
	
	Link Original do problema: https://www.urionlinejudge.com.br/judge/en/problems/view/1082
	
	ATENÇÃO! Pedimos que não veja as dicas da Solução até ter quebrado bastante a cabeça tentando resolver o problema :)

*/
#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>
#include <string.h>

#define MAXN 50

using namespace std;

int casos;
int n,e;
bool grafo[MAXN][MAXN];
bool transposto[MAXN][MAXN];
bool marcado[MAXN];
stack<int> termino; //Recuperação dos vértices
vector< vector<int> > saida; //Componente conexa
vector<int> componente;

int dfsComponents(int vertice){
	marcado[vertice] = true;

	for(int i=0;i<n;i++){
		if(!marcado[i] && grafo[vertice][i]){
			dfsComponents(i);
		}
	}
	termino.push(vertice);

	return 0;
}

int dfs(int vertice){
	marcado[vertice] = true;
	componente.push_back(vertice);

	for(int i=0;i<n;i++){
		if(!marcado[i] && transposto[vertice][i]){
			dfs(i);
		}
	}

	return 0;
}

int main (){
	scanf("%d",&casos);

	int caso = 0;
	while(caso < casos){
		saida.clear();
		caso++;

		//Initialization
		for(int i=0;i<MAXN;i++){
			for(int j=0;j<MAXN;j++){
				grafo[i][j] = transposto[i][j] = false;
			}
			marcado[i] = false;
		}


		scanf("%d %d",&n,&e);

		char a,b;
		for(int i=0;i<e;i++){
			scanf(" %c %c",&a,&b);
			grafo[a-97][b-97] = transposto[a-97][b-97] = true;
			transposto[b-97][a-97] = grafo[b-97][a-97] = true;
		}

		//Strongly Connected Components
		//1- Percorrer o grafo original
		
		for(int i=0;i<n;i++){
			if(!marcado[i]){
				dfsComponents(i);
			}
		}

		for(int i=0;i<MAXN;i++){
			marcado[i] = false;
		}


		//Percorrer o grafo transposto

		printf("Case #%d:\n",caso);

		int numeroComponentes = 0;
		while(!termino.empty()){
			int vertice = termino.top();
			termino.pop();

			if(marcado[vertice] == false){
				numeroComponentes++;

				dfs(vertice);
			}

			sort(componente.begin(),componente.end());

			
			if(!componente.empty()){
				saida.push_back(componente);
			}
			componente.clear();
		}
		vector<vector<int> >::reverse_iterator it1;
		vector<int>::iterator it2;

		for(it1 = saida.rbegin();it1 != saida.rend();++it1){
			for (it2 = it1->begin(); it2 != it1->end(); ++it2)
			{
				printf("%c,",(*it2+97));
			}
			printf("\n");
		}

		printf("%d connected components\n\n",numeroComponentes);
	}


	return 0;
}