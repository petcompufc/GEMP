/*
	URI1152.cpp - (URI) 1152 - Dark Roads

	Problema Off-Roteiro
	
	Link Original do problema: https://www.urionlinejudge.com.br/judge/en/problems/view/1152
	
	ATENÇÃO! Pedimos que não veja as dicas da Solução até ter quebrado bastante a cabeça tentando resolver o problema :)

*/
#include <stdio.h>
#include <stdlib.h>
#define MAXN 200200

typedef struct{
    int a,b;
    int peso;
}tipo_aresta;

tipo_aresta aresta[MAXN];
int pai[MAXN];

int crescente(const void *x,const void *y){
    if( ((tipo_aresta*)x)->peso  > ((tipo_aresta*)y)->peso )return 1;
    if( ((tipo_aresta*)x)->peso  < ((tipo_aresta*)y)->peso )return -1;
    return 0;
}

int find(int elemento){
    if (elemento == pai[elemento])return elemento;
    else return pai[elemento] = find(pai[elemento]);
}

int join(int vertA, int vertB){
    int paiA = find(vertA);
    int paiB = find(vertB);
    pai[paiB] = paiA;
    return 0;
}

int main(){
    int n,m;
    int pontoA,pontoB,custo;
    int custoTotal,custoMST;
    while(1){
        for (int i=0;i<MAXN;i++){
            pai[i] = i;
        }


        custoTotal = 0;
        custoMST = 0;

        scanf ("%d %d",&n,&m);

        if(n==0 && m==0)break;

        for (int i=0;i<m;i++){
            scanf ("%d %d %d",&pontoA,&pontoB,&custo);
            aresta[i].a = pontoA;
            aresta[i].b = pontoB;
            aresta[i].peso = custo;
            custoTotal += custo;
        }

        qsort(aresta,m,sizeof(tipo_aresta),crescente);

        for (int i=0;i<m;i++){

            if( find(aresta[i].a) != find(aresta[i].b) ){
                custoMST += aresta[i].peso;
                if(aresta[i].a<aresta[i].b)join(aresta[i].a,aresta[i].b);
                else join(aresta[i].b,aresta[i].a);
            }

        }

        printf("%d\n",custoTotal - custoMST);
    }
    return 0;
}
