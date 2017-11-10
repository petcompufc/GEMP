/*
	OBIPOKER.cpp - (SPOJ-BR) OBIPOKER

	Problema do Roteiro 1 - Problemas Ad-Hoc

	Link Original do problema: http://br.spoj.com/problems/OBIPOKER/
	Link para Dicas da Solução: http://wiki.maratona.dcc.ufmg.br/index.php/OBIPOKER

	ATENÇÃO! Pedimos que não veja as dicas da Solução até ter quebrado bastante a cabeça tentando resolver o problema :)

*/
#include <iostream>

using namespace std;


int main()
{
    int k;
    cin >> k;
    for (int i=1;i<=k;i++){
        int vec[] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
        int x,result=0,cont=0;
        for (int j=0;j<5;j++){
            cin >> x;
            vec[x-1]++;
        }
        for (int j=0;j<10;j++){
            if (vec[j]==1 && vec[j+1]==1 && vec[j+2]==1 && vec[j+3]==1 && vec[j+4]==1){
                result=200+j+1;
                goto teste;
            }
        }
        for (int j=0;j<13;j++){
            if (vec[j]==4){
                result=180+j+1;
                break;
            }
            else if (vec[j]==3){
                for (int u=0;u<13;u++){
                    if (vec[u]==2){
                        result=160+j+1;
                        goto teste;
                    }
                }
                result=140+j+1;
            }
            else if(vec[j]==2){
                for (int u=j+1;u<13;u++){
                    if (vec[u]==2){
                        result=(3*(u+1))+(2*(j+1))+20;
                        goto teste;
                    }
                }
                result=j+1;
            }
        }
        teste:
        cout << "Teste " << i << endl;
        cout << result << endl << endl;
    }
    return 0;
}
