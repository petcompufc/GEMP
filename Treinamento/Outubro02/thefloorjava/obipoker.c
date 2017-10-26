#include <stdio.h>
#include <stdlib.h>

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

void ordenaMao(int* vetor){
	int aux, i, j;
	int tamanho = 5;
  	for (i = 0; i < tamanho; i++) {
	  	for (j = 0; j < tamanho; j++){
			if (vetor[i] < vetor[j]){
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
		}
	}
}

int sequencia(int* mao){
	int i;
	int tam = 5; // numero de cartas
	for(i=0; i<tam; i++){
		if(mao[0] + i != mao[i])
			return 0;
	}
	return mao[0];
}

int quadra(int* mao){
	int i, igual, j = 0;
	int tam = 5; // numero de cartas
	int vetor[tam];
	for(i=0; i<tam; i++){
		igual = 0;
		for(j=0; j<tam; j++){
			if(j != i){
				if(mao[i] == mao[j]){
					igual++;
					if(igual == 3)
						return mao[i];
				}
			}
		}
	}	return 0;

}

int fullHouse(int* mao){
	int i, j, igual, igual2 = 0, trinca = 0;
	int tam = 5; // numero de cartas
	int vetor[tam];

	// verifica qual carta se repete 3 vezes
	for(i=0; i<tam; i++){
		igual = 0;
		for(j=0; j<tam; j++){
			if(j != i){
				if(mao[i] == mao[j]){
					igual++;
					if(igual == 2)
						trinca = mao[i];
				}
			}
		}
	}

	// verifica qual carta se repete 2 vezes
	for(i=0; i<tam; i++){
		for(j=0; j<tam; j++){
			if((mao[i] != trinca) && (i != j)){
				if(mao[i] == mao[j])
					igual2 = 1;
			}
		}
	}

	if(trinca && igual2)
		return trinca;

	return 0;
}

int trinca(int* mao){
	int i, j, igual;
	int tam = 5; // numero de cartas
	int vetor[tam];

	// verifica se há alguma carta que se repete 3 vezes
	for(i=0; i<tam; i++){
		igual = 0;
		for(j=0; j<tam; j++){
			if(j != i){
				if(mao[i] == mao[j]){
					igual++;
					if(igual == 2)
						return mao[i];
				}
			}
		}
	}

	return 0;
}

int doisPares(int* mao){
	int i, j, igual, par2 = 0, par = 0;
	int tam = 5; // numero de cartas
	int vetor[tam];

	// verifica qual carta se repete 2 vezes
	for(i=0; i<tam; i++){
		igual = 0;
		for(j=0; j<tam; j++){
			if(j != i){
				if(mao[i] == mao[j]){
					igual++;
					if(igual == 1)
						par = mao[i];
				}
			}
		}
	}

	// verifica qual a outra carta que se repete 2 vezes
	for(i=0; i<tam; i++){
		for(j=0; j<tam; j++){
			if((mao[i] != par) && (i != j)){
				if(mao[i] == mao[j])
					par2 = mao[i];
			}
		}
	}

	// retorna o maior par
	if(par && par2)
		return maior(par, par2);
	return 0;
}

int par(int* mao){
	int i, j, igual;
	int tam = 5; // numero de cartas
	int vetor[tam];

	// verifica se há alguma carta que se repete uma vez
	for(i=0; i<tam; i++){
		igual = 0;
		for(j=0; j<tam; j++){
			if(j != i){
				if(mao[i] == mao[j]){
					igual++;
					if(igual == 1)
						return mao[i];
				}
			}
		}
	}
	return 0;
}



int main(void){

	int mao[5];
	int n, i, j, k, x, y, tam = 5;
	int pontos;

	scanf("%d", &n);
	for(i=0; i<n; i++){
		
		//Leitura das cartas
		for(j=0; j<5; j++){
			scanf("%d", &mao[j]);
		}

		ordenaMao(mao);

		if(sequencia(mao)){
			x = sequencia(mao);
			pontos = 200 + x;
		}

		else if(quadra(mao)){
			x = quadra(mao);
			pontos = 180 + x;
		}

		else if(fullHouse(mao)){
			x = fullHouse(mao);
			pontos = 160 + x;
		}

		else if(trinca(mao)){
			x = trinca(mao);
			pontos = 140 + x;
		}

		else if(doisPares(mao)){
			x = doisPares(mao);

			// descarta o maior par da verificacao e analisa qual o segundo par
			for(k=0; k<tam; k++){
				for(j=0; j<tam; j++){
					if((mao[k] != x) && (k != j)){
						if(mao[k] == mao[j])
							y = mao[k];
					}
				}
			}

			pontos = 20 + 3*x + 2*y;
		}

		else if(par(mao)){
			x = par(mao);
			pontos = x;
		}

		else{
			pontos = 0;
		}
		printf("Teste %d\n", i+1);
		printf("%d\n\n", pontos);
	}

	return 0;
}
