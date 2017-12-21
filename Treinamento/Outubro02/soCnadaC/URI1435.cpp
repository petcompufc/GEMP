#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int entrada;
	scanf("%d",&entrada);
	while(entrada!=0)
	{
		int v[entrada][entrada];
		int i , j;
		int h;
		int teto;

		if (entrada%2==1)
		{
			teto=(entrada/2)+1;
		}
		else
		{
			teto=entrada/2;
		}


		for (h = 1; h <= teto; h++)
		{
				for ( i = h-1; i <= entrada-h; i++)
				{
					for ( j = h-1; j <= entrada-h; j++)
					{
						v[i][j]=h;
					}
				}
		}

int g , r;
for(g=0; g<entrada; g++)
            {
                for(r=0; r<entrada; r++)
                {
                    if(r==0)
                        printf("%3d",v[g][r]);
                    else printf(" %3d",v[g][r]);
                }
                printf("\n");
            }
		printf("\n");
		scanf("%d",&entrada);
	}
	return 0;
}