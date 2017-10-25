/*
	OBIPOKER.cpp - (SPOJ-BR) OBIPOKER

	Problema do Roteiro 1 - Problemas Ad-Hoc
	
	Link Original do problema: http://br.spoj.com/problems/OBIPOKER/
	Link para Dicas da Solução: http://wiki.maratona.dcc.ufmg.br/index.php/OBIPOKER

	ATENÇÃO! Pedimos que não veja as dicas da Solução até ter quebrado bastante a cabeça tentando resolver o problema :)

*/
#include <iostream>

using namespace std;

int main() {
	int N, C[5], i, j, k, t, pts;
	int nx, ny, nz, x, y, z;

	cin >> N;
	for( i=0; i<N; i++ ){
		for( j=0; j<5; j++ )
			cin >> C[j];
		
		for( j=0; j<4; j++ )
		   for( k=j+1; k>0 && C[k]>C[k-1]; k--){
			   t = C[k];
			   C[k] = C[k-1];
			   C[k-1] = t;
		   }

		x = C[0];	y = 0;	z = 0;
		nx = 1;		ny = 1; nz = 1;
		for( j=1; j<5 && C[j] == x; j++ )
				nx++;
		y = C[j];
		for(j++; j<5 && C[j]==y; j++)
			ny++;
		if(j<5){
		   z = C[j];
			for(j++; j<5 && C[j]==z; j++)
				nz++;
		}
		if(!z){
			if( nx > 2 ) pts = x+(100 + nx*20);
			else if( ny > 2 ) pts = y+(100 + ny*20);
			}
		else{
				// organizar x y e z
			if( nx < ny ){
				j = nx;	nx = ny; ny = j;
				j = x; x = y; y = j;
			}
			if( ny < nz){
				j = ny; ny = nz; nz = j;
				j = y; y = z; z = j;
			}
			if( nx < ny ){
				j = nx;	nx = ny; ny = j;
				j = x; x = y; y = j;
			}

			if( nx == 3 ) pts = x+140;
			else if( nx+ny == 4 )
				pts = 3*x + 2*y +20;
			else if( nx == 2 ) pts = x;
			else if( (C[0] - C[4]) == 4 )
				pts = C[4] + 200;
			else pts = 0;

		}
		cout << "Teste " << i+1 << endl << pts << endl;
	}

	return 0;
}
