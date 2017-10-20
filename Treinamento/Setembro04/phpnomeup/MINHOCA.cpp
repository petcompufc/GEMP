/*
	MINHOCA.cpp - (SPOJ-BR) MINHOCA

	Problema do Roteiro 0 - Primeiros Problemas

	Link Original do problema: http://br.spoj.com/problems/MINHOCA/
	Link para Dicas da Solução: http://wiki.maratona.dcc.ufmg.br/index.php/MINHOCA

	ATENÇÃO! Pedimos que não veja as dicas da Solução até ter quebrado bastante a cabeça tentando resolver o problema :)

*/
/*
//Solução - ÍTALO
#include <iostream>

using namespace std;

int main(){
	int m, n, i, j, saida, somai, somaj;
	scanf("%d %d" , &n, &m);
	int area[n][m];

	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			cin >> area[i][j];
		}
	}

	saida = 0;
	for (j = 0, somaj = 0; j < m; somaj = 0, j++){
		for (i = 0; i < n; i++){
			somaj += area[i][j];
//			somai += area[j][i];
		}

		if (somaj>saida) saida = somaj;
//		if (somai>saida) saida = somai;
	}
	for (i = 0, somai = 0; i < n; somai = 0, i++){
		for (j = 0; j < m; j++){
			somai += area[i][j];
		}
		if (somai>saida) saida = somai;
	}

	cout << saida;

	return 0;
}
*/
//Solução - JONAS
#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    int campo[n][m];
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> campo[i][j];
        }
    }

    int maiorL=0,maiorC=0,totalL=0,totalC=0;
    for (int i=0; i<n; i++){
        maiorL=0;
        for (int j=0; j<m; j++){
            maiorL+=campo[i][j];
        }
        if (maiorL>totalL)
            totalL=maiorL;
    }
    for (int i=0; i<m; i++){
        maiorC = 0;
        for (int j=0; j<n; j++){
            maiorC+=campo[j][i];
        }
        if (maiorC>totalC)
            totalC=maiorC;
    }
    if (totalC>totalL)
        cout << totalC << endl;
    else
        cout << totalL << endl;
    return 0;
}

