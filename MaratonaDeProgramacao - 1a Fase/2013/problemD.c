#include <stdio.h>
#include <math.h>

void printArray(int* array, int size)
{
	for(int i = 0; i < size; i++)
		printf("%d ", array[i]);

	printf("\n");
}

bool compareArray(int* inFita, int inSize, int* outFita, int outSize)
{
	if(inSize != outSize)
		return false;
	else
	{
		for(int i = 0; i < inSize; i++)
			if(inFita[i] != outFita[i])
				return false;		
	}

	return true;
}

bool dobraRecursiva(int* inFita, int* outFita, int inSize, int outSize, int dobra)
{
	/*
		TESTES
	printf("In: ");
	printArray(inFita, inSize);
	*/
	
	if(compareArray(inFita, inSize, outFita, outSize))
		return true;
	else if(inSize < outSize)
		return false;

	const int tempSize = inSize/2+fabs(inSize/2 - dobra);
	int tempFita[tempSize];

	for(int i = 0; i < tempSize; i++)
	{
		tempFita[(tempSize - 1) - i] = 0;
		if(dobra - i > 0) tempFita[(tempSize - 1) - i] += inFita[(dobra - 1) - i];
		if(dobra + i < inSize) tempFita[(tempSize - 1) - i] += inFita[dobra + i];
	}
	
	/*
		TESTES
	printf("Temp: ");
	printArray(tempFita, tempSize);
	*/
	
	bool founded = false;
	if(dobra != 0)
		founded = dobraRecursiva(tempFita, outFita, tempSize, outSize, 0);

	for(int i = 1; i < tempSize; i++)
		if(!founded) founded = dobraRecursiva(tempFita, outFita, tempSize, outSize, i);		

	return founded;
}

bool dobraRecursiva(int* inFita, int* outFita, int inSize, int outSize)
{
	for(int i = 0; i < inSize; i++){
		if(dobraRecursiva(inFita, outFita, inSize, outSize, i))
			return true;
	}
	
	return false;
}

int main()
{
	// Entrada de Dados
	// Fita de Entrada
	int inSize;
	scanf("%d", &inSize);

	int inFita[inSize];

	int i = 0;
	while(scanf("%d", &inFita[i++]) && i < inSize);

	// Fita de Saída
	int outSize;
	scanf("%d", &outSize);

	int outFita[outSize];

	int j = 0;
	while(scanf("%d", &outFita[j++]) && j < outSize);

	// Dobraduras Recursivas
	if(dobraRecursiva(inFita, outFita, inSize, outSize))
		printf("S\n");
	else
		printf("N\n");

	return 0;
}
