#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n ,m , i ,j,soma_linha=0,soma_coluna=0,maior_linha=0,maior_coluna=0;

	scanf("%d %d",&n,&m);
	int v[n][m];

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d",&v[i][j]);
		}
	}


	for (i = 0; i < n; i++)
	{
		soma_linha=0;
		for (j = 0; j < m; j++)
		{
			soma_linha+=v[i][j];
		}

		if (soma_linha>maior_linha)
		{
			maior_linha = soma_linha;
		}
	}

	for (i = 0; i < m; i++)
	{
		soma_coluna=0;
		for (j = 0; j < n; j++)
		{
			soma_coluna+=v[j][i];
		}

		if (soma_coluna>maior_coluna)
		{
			maior_coluna = soma_coluna;
		}
	}

	if (maior_coluna>maior_linha)
	{
		printf("%d\n",maior_coluna);
	}
	else
	{
		printf("%d\n",maior_linha);
	}


	return 0;
}