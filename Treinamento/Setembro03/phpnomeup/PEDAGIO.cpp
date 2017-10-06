/*
	PEDAGIO.cpp - (SPOJ-BR) PEDAGIO

	Problema do Roteiro 5 - Algoritmos em Grafos pt.1
	
	Link Original do problema: http://br.spoj.com/problems/PEDAGIO/
	Link para Dicas da Solução: http://wiki.maratona.dcc.ufmg.br/index.php/PEDAGIO

	ATENÇÃO! Pedimos que não veja as dicas da Solução até ter quebrado bastante a cabeça tentando resolver o problema :)

*/
#include <cstdio>
#include <cstring>
#define MAXC 60
#define INF 999999999
#define minimo(A,B) ((A)<(B))?(A):(B)

using namespace std;

int estrada[MAXC][MAXC];

int main (){
    int teste = 0;
    int cid,est,atual,pedagio;

    while (1){
        teste++;

        for (int i=0;i<MAXC;i++)
        for (int j=0;j<MAXC;j++)
            estrada[i][j] = INF;

        scanf ("%d %d %d %d",&cid,&est,&atual,&pedagio);

        if (cid == 0 && est == 0 && atual == 0 && pedagio == 0)break;

        int x,y;
        for (int i=0;i<est;i++){
            scanf ("%d %d",&x,&y);
            estrada[x][y] = 1;
            estrada[y][x] = 1;
        }

        //Floyd-Warshall Algorithm
        for (int k=1;k<=cid;k++)
        for (int i=1;i<=cid;i++)
        for (int j=1;j<=cid;j++){
            estrada[i][j] = minimo(estrada[i][j],estrada[i][k] + estrada[k][j]);
        }

        printf ("Teste %d\n",teste);

        for (int i=1;i<=cid;i++){
            if (i!=atual && estrada[atual][i]<=pedagio){
                printf ("%d ",i);
            }
        }

        printf ("\n\n");
    }

    return 0;
}
