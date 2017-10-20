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
    int N,i,j,contador,aux;

    while ((cin>>N) && N!=0) {
        int M[N][N];
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                M[i][j]=0;
            }
        }

        aux=N;
        contador=0;

        if(aux==1||aux==2){
            if(aux==1){
                cout<<"  1"<<endl;
                cout<<endl;
            }
            else{
                cout<<"  1   1"<<endl;
                cout<<"  1   1"<<endl;
                cout<<endl;
            }
        }
        else{

            while((aux-2)>=0){
                for(i=contador;i<aux;i++){
                    for(j=contador;j<aux;j++){
                        M[i][j]+=1;
                    }
                }
                aux--;
                contador++;
            }

            for(i=0;i<N;++i){
                for(j=0;j<N;++j){
                    cout<<setw(3);
                    if(j+1==N) cout<<M[i][j]<<endl;
                    else cout<<M[i][j]<<" ";
                }
            }
            cout<<"\n";
        }
    }

  return 0;

}
