#include <stdio.h>
#include <math.h>

bool isPrime(long long n){
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

long long calcularTotiente(int n)
{
	long long primos[6000];

	long long k = 0, i = 3;
	while(k < 6000) {
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
	long long n, e, c;
	long long d = 1, message = 1;
	long long totiente;

	scanf("%lld %lld %lld", &n, &e, &c);

	totiente = calcularTotiente(n);
	
	while((d * e) % totiente != 1)
		d++;

	for(int i = 0; i < d; i++)
		message = (message * c) % n;

	printf("%lld\n", message);

	return 0;
}