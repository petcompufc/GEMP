#include <stdio.h>

int fatorial(int n)
{
	int i, j;
	for(j = i = 1; i <= n; j *= i++);
	return j;
}

int main()
{
	int N;

	scanf("%d", &N);

	int k = 0;
	while(N > 0)
	{
		int i;
		for(i = 1; fatorial(i) <= N; i++);

		N -= fatorial(i - 1);
		k++;
	}

	printf("\n%d", k);

	return 0;
}
