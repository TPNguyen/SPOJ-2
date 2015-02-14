#include <iostream>

using namespace std;

int main()
{
	int t, n, bank, temp;

	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cin >> n >> bank;
		for (int j = 0; j < n - 1; ++j)
		{
			cin >> temp;
			cout << temp << " ";
		}
		cout << bank << endl;
	}
	return 0;
}
