#include <iostream>

using namespace std;

int main()
{
	int t, v1, v2;

	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		cin >> v1 >> v2;
		cout << 2 * v1 * v2 / (v2 + v1) << endl;
	}

	return 0;
}
