#include <iostream>

using namespace std;

int main()
{
	int a = 42, ap, i = 0;

	do
	{
		ap = a;
		cin >> a;
		if (a == 42 && ap != 42)
			++i;
		cout << a << endl;
	} while (i < 3);

	return 0;
}
