#include <stdio.h>
#include <stdlib.h>

int sentinela(int w, int h, int n){
	if(w == h && h == n && n == 0) 
		return 1;

	return 0;
}

int maior(int n1, int n2){
	if(n1 > n2) 
		return n1;

	return n2;
}

int menor(int n1, int n2){
	if(n1 < n2) 
		return n1;

	return n2;
}

int main(void){

	int w, h, n;
	int x1, y1, x2, y2;
	int i, j, k;
	int soma;
	int vetor[500][500];

	while(1){
		
		scanf("%d %d %d", &w, &h, &n);

		if(sentinela(w, h, n)) break; // se as entradas forem 0 o programa encerra

		// zera vetor
		for(i=0; i<500; i++){
			for(j=0; j<500; j++){
				vetor[i][j] = 0;
			}
		}

		// le as coordenadas
		for(i=0; i<n; i++){
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

			x1--; y1--;
			x2--; y2--;

			// coloca 1 nos elementos das subpartes
			for(j=menor(x1, x2); j<=maior(x1, x2); j++){
				for(k=menor(y1, y2); k<=maior(y1, y2); k++){
					vetor[j][k] = 1;
				}	
			}

		}

		soma = 0;

		// verifica os elementos livres e incrementa em soma
		for(j=0; j<w; j++){
			for(k=0; k<h; k++){
				if(vetor[j][k] == 0) soma++;
			}	
		}

		if(soma == 0)
			printf("There is no empty spots.\n");
		if(soma == 1)
			printf("There is one empty spot.\n");
		if(soma > 1)
			printf("There are %d empty spots.\n", soma);

	}

	return 0;
}