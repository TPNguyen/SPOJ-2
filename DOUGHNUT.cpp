#include <iostream>

using namespace std;

int main()
{
	int t, c, k, w;

	cin >> t;

	while (t--)
	{
		cin >> c >> k >> w;
		cout << (k >= w * c?"yes":"no") << endl;
	}

	return 0;
}
