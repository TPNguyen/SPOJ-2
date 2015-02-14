#include <iostream>

using namespace std;

int main()
{
	double a, b, c;

	cin >> a >> b >> c;

	cout.precision(2);

	if (a == 0 && b != c)
		cout << "BR";
	else if (a == 0)
		cout << "NWR";
	else
		cout << fixed << (c - b) / a;

	return 0;
}
