#include <iostream>
#include <string>

using namespace std;

unsigned long long int nwd(unsigned long long int, unsigned long long int);
unsigned long long int nww(unsigned long long int, unsigned long long int);

int main()
{
	int t, n;
	unsigned long long int a, result;

	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		cin >> n;
		if (n == 0)
			continue;
		cin >> result;
		for (int j = 0; j < n - 1; ++j)
		{
			cin >> a;
			result = nww(result, a);
		}
		cout << result << endl;
	}

	return 0;
}

unsigned long long int nwd(unsigned long long int a, unsigned long long int b)
{
	unsigned long long int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

unsigned long long int nww(unsigned long long int a, unsigned long long int b)
{
	return a * (b / nwd(a, b));
}
