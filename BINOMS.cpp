#include <iostream>

using namespace std;

unsigned long long int symbolNewtona(int, int);

int main()
{
	int t, n, k;

	cin >> t;
	
	while (t--)
	{
		cin >> n >> k;
		cout << symbolNewtona(n, k) << endl;
	}

	return 0;
}

/*
unsigned long long int symbolNewtona(unsigned long long int n, unsigned long long int k)
{
	if (k == 0 || k == n)
		return 1;
	else
		return symbolNewtona(n - 1, k - 1) + symbolNewtona(n - 1, k);
}
*/

/*
unsigned long long int symbolNewtona(unsigned long long int n, unsigned long long int k)
{
	unsigned long long int res = 1;

	for (unsigned long long int i = 0; i < k; ++i)
		res = res * (n - i) / (i + 1);

	return res;
}
*/

unsigned long long int symbolNewtona(int n, int k)
{
	if (k == 0 || n == k)
		return 1;
	if (k > n)
		return 0;
	if (k > (n - k))
		k = n - k;
	if (k == 1)
		return n;
	unsigned long long int b = 1;
	for (int i = 1; i <= k; ++i)
	{
		b *= (n - (k - i));
		if (b < 0) 
			return -1; //overflow
		b /= i;
	}
	return b;
}
