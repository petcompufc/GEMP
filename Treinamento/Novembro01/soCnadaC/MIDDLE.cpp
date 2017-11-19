/*
	MIDDLE.cpp - (PKU) Who's In The Middle?
	Problema do Roteiro 2 - Estruturas de Dados
	
	Link Original do problema: http://poj.org/problem?id=2388
	Link para Dicas da Solução: http://wiki.maratona.dcc.ufmg.br/index.php/PKU_2388
	ATENÇÃO! Pedimos que não veja as dicas da Solução até ter quebrado bastante a cabeça tentando resolver o problema :)
*/

#include <iostream>     
#include <algorithm>    
#include <vector>       

using namespace std;

int main () 
{
  	int n;
  	int i ,aux,j,middle;
  	vector<int> lista;

  	cin >> n;
  	middle = n/2;
  
  	for(i=1;i<=n;i++)
  	{
    	cin>> aux;
    	lista.push_back(aux);
  	}

  	sort (lista.begin(), lista.end());
  
  	cout << lista[middle];
  	cout << '\n';

  	return 0;
}