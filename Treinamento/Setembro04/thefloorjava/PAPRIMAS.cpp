/*
	PAPRIMAS.cpp - (SPOJ-BR) PAPRIMAS

	Problema do Roteiro 0 - Primeiros Problemas
	
	Link Original do problema: http://br.spoj.com/problems/PAPRIMAS/
	Link para Dicas da Solução: http://wiki.maratona.dcc.ufmg.br/index.php/PAPRIMAS

	ATENÇÃO! Pedimos que não veja as dicas da Solução até ter quebrado bastante a cabeça tentando resolver o problema :)

*/
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{	int num,sum = 0;
	char cha;
	bool isPrime;
	while(cin.get(cha)){
		if(cha != '\n'){
			num = cha;
			if(num > 90){
				num += -96;
			}else{
				num += -38;
			}
			sum += num;
		}else{
		    if(sum == 1){
                isPrime = true;
            }else{
                for(int i = 2; i < sum; ++i){
                    if(sum % i == 0){
                        isPrime = false;
                        break;
                    }
                    isPrime = true;
                }
            }
			if(isPrime){
				cout << "It is a prime word." << endl;
			}else{
				cout << "It is not a prime word." << endl;
			}
			sum = 0;
		}
	}
	return 0;
}