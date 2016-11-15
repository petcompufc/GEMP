#include <stdio.h>
#include <stdlib.h>

int missingNumber(int *vetor, int i, int j, int size, int diff)
{
	int m = (j+i)/2;

	printf("i: %d | j: %d | diff: %d --> ", i, j, diff);
	printf("%d %d\n", vetor[m], vetor[0] + m * diff);

	if(m > 0 && vetor[m-1] != vetor[m] - diff)
		return vetor[m] - diff;
	else if(m < size && vetor[m+1] != vetor[m] + diff)
		return vetor[m] + diff;

	if(vetor[m] != vetor[0] + m * diff)
		return missingNumber(vetor, i, m - 1, size, diff);
	else
		return missingNumber(vetor, m + 1, j, size, diff);
}

int main()
{
	int size;
	int *vetor;

	scanf("%d", &size);

	vetor = (int*) malloc(sizeof(int) * size);

	for(int i = 0; i < size; i++) scanf("%d", &vetor[i]);

	printf("%d\n", missingNumber(vetor, 0, size-1, size, (vetor[size-1] - vetor[0])/size));

	return 0;
}