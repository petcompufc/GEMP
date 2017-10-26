/*
	URI1435.cpp - (URI) 1435 - Matriz Quadrada I

	Problema do Roteiro 1 - Problemas Ad-Hoc

	Link Original do problema: https://www.urionlinejudge.com.br/judge/pt/problems/view/1435
	Link para Dicas da Solução: http://wiki.maratona.dcc.ufmg.br/index.php/URI1435

	ATENÇÃO! Pedimos que não veja as dicas da Solução até ter quebrado bastante a cabeça tentando resolver o problema :)

*/
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    while (cin >> n && n!=0){
        if (n==1){
            printf ("%3d\n\n", 1);
        }
        else{
            int m[n][n];
            for (int i=0;i<n;i++){
                for (int j=0;j<n;j++){
                    m[i][j]=0;
                }
            }
            int L=n+1,k=0;
            do{
                for (int i=k;i<n-k;i++){
                    for (int j=k;j<n-k;j++){
                        m[i][j]++;
                    }
                }
                k++;
                L--;
            }while(L-2>0);

            for (int i=0;i<n;i++){
                for (int j=0;j<n-1;j++){
                    printf ("%3d ", m[i][j]);
                }
                printf ("%3d\n", m[i][n-1]);
            }
            cout << endl;
        }
    }

	return 0;
}
