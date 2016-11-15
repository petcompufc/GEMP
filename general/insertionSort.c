#include <stdio.h>

void insertionSort(int* vetor, int tamanho)
{
	for(int i = 2; i < tamanho; i++)
	{
		int chave = vetor[i];
		int j = i-1;

		while(j >= 0 && chave < vetor[j])
		{
			vetor[j+1] = vetor[j];
			j--;
		}

		vetor[j+1] = chave;
	}
}

void printVetor(int* vetor, int tamanho)
{
	for(int i = 0; i < tamanho; i++)
		printf("%d - ", vetor[i]);

	printf("\n");
}

int main()
{
	int vetor[12] = {1, 4, 10, 3, 21, 5, 15, 16, 2, 9, 12, 19};

	insertionSort(vetor, 12);

	printVetor(vetor, 12);

	return 0;
}