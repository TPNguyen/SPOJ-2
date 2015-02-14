#include <iostream>

using namespace std;

bool prime(int);

int main()
{
	int n, x, i;

	cin >> n;

	for (i = 0; i < n; ++i)
	{
		cin >> x;
		cout << (prime(x)?"TAK":"NIE") << endl;
	}

	return 0;
}

bool prime(int x)
{
	if (x == 1)
		return false;

	for (int i = 2; i <= x / 2; ++i)
		if (!(x % i)) // jezeli reszta jest rowna 0, czyli sie dzieli
			return false;
	return true;
}
