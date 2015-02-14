#include <iostream>

using namespace std;

int main()
{
	double a, b, c;

	while (cin >> a >> b >> c)
		cout << ((a > b + c || b > a + c || c > a + b)?0:1) << endl;

	return 0;
}
