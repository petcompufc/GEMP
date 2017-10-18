/*
	URI1435.cpp - (URI) 1435 - Matriz Quadrada I

	Problema do Roteiro 1 - Problemas Ad-Hoc
	
	Link Original do problema: https://www.urionlinejudge.com.br/judge/pt/problems/view/1435
	Link para Dicas da Solução: http://wiki.maratona.dcc.ufmg.br/index.php/URI1435

	ATENÇÃO! Pedimos que não veja as dicas da Solução até ter quebrado bastante a cabeça tentando resolver o problema :)

*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	int N;
	int *matriz;
	int tamanho;


	do{
		cin >> N;
		if(N == 0){
			return 0;
		}
		tamanho = N*N;
		matriz = new int[tamanho];
		int pMedio = (N+1)/2 - 1;

		int linha = 0;
		int coluna = 0;
		int inicio = 0;
		int fim = N-1;
		int valor = 1;
		int cont2 = 0;

		if(N%2 != 0){
			matriz[N*pMedio + pMedio] = pMedio + 1;

		}

		while(cont2 != tamanho){
			matriz[N*linha + coluna] = valor;

			if(linha == inicio+1 && coluna == (N-fim-1)){
				++coluna;
				++inicio;
				--fim;
				++valor;
			}else if(linha == inicio && coluna != fim){
				++coluna;
			}else if(linha != fim && coluna == fim){
				++linha;
			}else if(linha == fim && coluna != inicio){
				--coluna;
			}else if(linha != inicio && coluna == inicio){
				--linha;
			}

			++cont2;

		}

		for(int linha = 0; linha < N; ++linha){
			for(int coluna = 0; coluna < N; ++coluna){
				cout << setw(3);
				if(coluna+1 == N){
					cout << matriz[N*linha + coluna] << endl;
				}else{
					cout << matriz[N*linha + coluna] << " ";
				}
			}
		}

		cout << endl;
	}while(N != 0);

	return 0;
}
