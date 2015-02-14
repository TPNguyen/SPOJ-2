#include <iostream>

using namespace std;

int fib(int);

int main()
{
	int t, n, m;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cin >> n >> m;
		cout << fib(n) % m << endl;
	}
	return 0;
}

int fib(int x)
{
	if (x < 2)
		return x;
	
	return (fib(x - 1) + fib(x - 2));
}
