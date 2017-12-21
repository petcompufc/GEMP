#include <stdio.h>
#include <string>

int main(int argc, char const *argv[])
{
	char v[20];
	int i,soma=0,divisor;

	for (i = 0; i < 20; i++)
	{
		v[i]=0;
	}

	while(scanf("%s",v)!=EOF)
	{
		soma=0;

		for (i = 0; i < 20; i++)
		{
			if (v[i]>=97 && v[i]<=122)
			{
				soma+=v[i]-96;
			}
			else if (v[i]>=65 && v[i]<=90)
			{
				soma+=v[i]-38;	
			}
		}

		divisor=1;

		for ( i = 2; i <= soma/2; i++)
		{
			if (soma%i==0)
			{
				divisor=soma%i;
				break;
			}
		}
		if (divisor!=1)
		{
			printf("It is not a prime word.\n");
		}
		else
		{
			printf("It is a prime word.\n");	
		}

		for (i = 0; i < 20; i++)
		{
			v[i]=0;
		}
	}


	return 0;
}