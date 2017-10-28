/*
	POSLIVRE.cpp - (SPOJ-BR) POSLIVRE

	Problema do Roteiro 1 - Problemas Ad-Hoc
	
	Link Original do problema: http://br.spoj.com/problems/POSLIVRE/
	Link para Dicas da Solução: http://wiki.maratona.dcc.ufmg.br/index.php/POSLIVRE

	ATENÇÃO! Pedimos que não veja as dicas da Solução até ter quebrado bastante a cabeça tentando resolver o problema :)

*/

#include <iostream>

using namespace std;

int main(){

  int w,h,n,i,j,x1,x2,y1,y2,aux,spots;

  while((cin>>w>>h>>n)&&(w+h+n)!=0){

    spots=0;
    int matriz[h][w];

    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            matriz[i][j]=1;
        }
    }

    while (n>0) {
      cin>>x1>>y1>>x2>>y2;

      if(x1>x2){
        aux=x2;
        x2=x1;
        x1=aux;
      }

      if(y1>y2){
        aux=y2;
        y2=y1;
        y1=aux;
      }

      for(i=x1-1;i<x2;i++){
        for(j=y1-1;j<y2;j++){
          matriz[j][i]=0;
        }
      }

      n--;
    }

    for(i=0;i<h;i++){
      for(j=0;j<w;j++){
        spots += matriz[i][j];
      }
    }
    if (spots>1) {
      cout<<"There are "<<spots<<" empty spots."<<endl;
    }
    else if (spots==1) {
      cout<<"There is one empty spot."<<endl;
    }
    else {
      cout<<"There is no empty spots."<<endl;
    }

    cout<<endl;
  }

  return 0;

}
