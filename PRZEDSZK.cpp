#include <iostream>
#include <string>

using namespace std;

int nwd(int, int);
int nww(int, int);

int main()
{
	int t, a, b;

	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		cin >> a >> b;
		cout << nww(a, b) << endl;
	}

	return 0;
}

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

int nww(int a, int b)
{
	return a * (b / nwd(a, b));
}

