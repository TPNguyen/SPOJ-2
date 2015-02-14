#include <iostream>

using namespace std;

int main()
{
	int t, n, a;
	int *tab;

	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		cin >> n;
		tab = new int[(n + 1) / 2];

		for (int j = 0; j < n; ++j)
		{
			if (j % 2)
			{
				cin >> a;
				cout << a << " ";
			}
			else
			{
				cin >> *tab++;
			}
		}
		tab = tab - (n + 1) / 2;
		for (int j = 0; j < (n + 1) / 2; ++j)
			cout << *tab++ << " ";
		tab = tab - (n + 1) / 2;
		cout << endl;
		delete [] tab;
	}

	return 0;
}
