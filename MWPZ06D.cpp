#include <iostream>

using namespace std;

int main()
{
	int t, l, c;

	cin >> t;

	while (t--)
	{
		cin >> l >> c;
		if (l > 1)
			cout << (c % (l - 1)?"TAK":"NIE") << endl;
		else
			cout << (c > 0?"TAK":"NIE") << endl;
	}

	return 0;
}
