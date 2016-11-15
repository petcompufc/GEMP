#include <stdio.h>

void printVetor(int* vetor, int tamanho)
{
	printf("%d", vetor[0]);
	for(int i = 1; i < tamanho; i++)
		printf(" - %d", vetor[i]);
	printf("\n");
}

void merge(int* L1, int tamanho1, int* L2, int tamanho2)
{
	int L3[tamanho1+tamanho2];
	int contL1 = 0, contL2 = 0;

	for(int i = 0; i < tamanho1+tamanho2; i++)
	{
		if(L1[contL1] < L2[contL2] && contL1 < tamanho1) {
			L3[i] = L1[contL1];
			contL1++;
		}
		else if(contL2 < tamanho2){
			L3[i] = L2[contL2];
			contL2++;
		}
	}

	printVetor(L3, tamanho1+tamanho2);
}

int main()
{
	int vetor1[5] = {1, 5, 9, 12, 15};
	int vetor2[5] = {3, 4, 11, 16, 19};

	merge(vetor1, 5, vetor2, 5);

	return 0;
}


// Algoritmo: Entrelaçar
// Entradas: duas listas L1 e L2.
// Saída: uma lista L3, representando a união ordenada de L1 e L2
// ---------------------------------------------------------------
// 1. | DECLARE L3 LISTA DE TAMANHO |L1|+|L2|
// 2. | cont1 <- 0; cont2 <- 0;
// 3. | 
// 4. | PARA i DE L3[1] ATE L3[n] FAÇA:
// 5. |  | SE (L1[cont1] < L2[cont2]) E cont1 < |L1|
// 6. |  |  | L3[i] <- L1[cont1]
// 7. |  |  | cont1 = cont1 + 1
// 8. |  | SENAO SE cont2 < |L2|
// 9. |  |  | L3[i] <- L2[cont2]
// 10.|  |  | cont2 = cont2 + 1