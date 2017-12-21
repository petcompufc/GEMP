#include <stdio.h>

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int v[n][n];
		int i,j;
		for ( i= 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				v[i][j]=3;
				if (i==j)
				{
					v[i][j]=1;
				}
				if (i+j==n-1)
				{
					v[i][j]=2;
				}
			}
		}

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				printf("%d",v[i][j]);
			}
			printf("\n");
		}

	}
	return 0;
}