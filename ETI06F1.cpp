#include <iostream>

using namespace std;

int main()
{
	double r, d;
	const double PI = 3.141592654;

	cin >> r >> d;
	cout << fixed << PI * (r * r - 0.25 * d * d);

	return 0;
}
