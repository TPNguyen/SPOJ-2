#include <iostream>

using namespace std;

int main()
{
	int t, n, x;

	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		cin >> x;
		n = 0;

		while (x != 1)
		{
			if (x % 2)
				x = 3 * x + 1;
			else
				x = x / 2;

			++n;
		}
		
		cout << n << endl;
	}

	return 0;
}
