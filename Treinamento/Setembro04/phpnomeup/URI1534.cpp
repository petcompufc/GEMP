/*
	URI1534.cpp - (URI) 1534 - Array 123

	Problema do Roteiro 0 - Primeiros Problemas

	Link Original do problema: https://www.urionlinejudge.com.br/judge/pt/problems/view/1534
	Link para Dicas da Solução: http://wiki.maratona.dcc.ufmg.br/index.php/URI1534

	ATENÇÃO! Pedimos que não veja as dicas da Solução até ter quebrado bastante a cabeça tentando resolver o problema :)

*/
#include <iostream>

using namespace std;

int main()
{
	int n;
    while (cin>>n){
        int m[n][n];
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (i==(n-1-j))
                    m[i][j]=2;
                else if (i==j)
                    m[i][j]=1;
                else
                    m[i][j]=3;
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<n-1;j++){
                cout << m[i][j];
            }
            cout << m[i][n-1] << endl;
        }
    }
	return 0;
}
