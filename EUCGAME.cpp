#include <iostream>

using namespace std;

int nwd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main()
{
	int a, b, t;

	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		cin >> a >> b;

		cout << 2 * nwd(a, b) << endl;
	}

	return 0;
}
