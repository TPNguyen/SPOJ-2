#include <iostream>

using namespace std;

int main()
{
	int t, a, n, x, y;

	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		cin >> n >> x >> y;
		
		a = x;
		while (a < n)
		{
			if (a % y)
				cout << a << " ";
			a += x;
		}
		cout << endl;
	}

	return 0;
}
