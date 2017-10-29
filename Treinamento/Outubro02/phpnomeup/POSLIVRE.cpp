/*
	POSLIVRE.cpp - (SPOJ-BR) POSLIVRE

	Problema do Roteiro 1 - Problemas Ad-Hoc

	Link Original do problema: http://br.spoj.com/problems/POSLIVRE/
	Link para Dicas da Solução: http://wiki.maratona.dcc.ufmg.br/index.php/POSLIVRE

	ATENÇÃO! Pedimos que não veja as dicas da Solução até ter quebrado bastante a cabeça tentando resolver o problema :)

*/
#include <iostream>

using namespace std;

bool m[501][501];

int main()
{
    int w,h,n;
    while (cin >> w >> h >> n){
        if (w==0 && h==0 && n==0){
            break;
        }
        for (int i=1; i<=h;i++){
            for (int j=1; j<=w; j++){
                m[i][j]=true;
            }
        }

        for (int k=0; k<n; k++){
            int x1,y1,x2,y2,temp;
            cin >> y1 >> x1 >> y2 >> x2;
            if (x1>x2){
                temp = x1;
                x1 = x2;
                x2 = temp;
            }
            if (y1>y2){
                temp = y1;
                y1 = y2;
                y2 = temp;
            }
            for (int i=x1; i<=x2; i++){
                for (int j=y1; j<=y2; j++){
                    m[i][j]=false;
                }
            }
        }
        int cont=0;
        for (int i=1; i<=h;i++){
            for (int j=1; j<=w; j++){
                if (m[i][j]==true)
                    cont++;
            }
        }
        if (cont==0)
            cout << "There is no empty spots." << endl;
        else if (cont==1)
            cout << "There is one empty spot." << endl;
        else
            cout << "There are " << cont << " empty spots." << endl;
    }
    return 0;
}
