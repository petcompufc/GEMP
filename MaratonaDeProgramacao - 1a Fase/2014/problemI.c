#include <stdio.h>
#include <math.h>

bool isPrime(int n){
    if (n <= 1)
        return false;
    else if (n <= 3)
        return true;
    else if ((n % 2) == 0 || (n % 3) == 0)
        return false;
    for(int i = 5; i*i <= n; i+=6) {
        if ((n % i == 0) | (n % (i + 2)) == 0)
            return false;
    }
        return true;
}

int calcularTotiente(int n)
{
	int primos[1230];

	int k = 0, i = 3;
	while(k < 1230) {
		if(isPrime(i))
			primos[k++] = i;
		i++;
	}

	int p = 0, q = 1;
	while ((primos[p] * primos[q]) != n)
	{
		if(primos[q] * primos[p] > n || q >= k)	{
			p++;
			q = 0;
		}
		else
			q++;
	}

	return (primos[p] - 1) * (primos[q] - 1);
}

int main()
{
	int n, e, c;
	int d = 1, message = 1;
	int totiente;

	scanf("%d %d %d", &n, &e, &c);

	totiente = calcularTotiente(n);
	
	while((d * e) % totiente != 1)
		d++;

	for(int i = 0; i < d; i++)
		message = (message * c) % n;

	printf("%d\n", message);

	return 0;
}