#include <iostream>

using namespace std;

int main(void)
{
	int t, n, i, k;
	int d[100];
	int *ptr;
	int *ptr2;
	
	cin >> t;

	for (i = 0; i < t; ++i)
	{
		cin >> n;
		ptr = d;
		ptr2 = d + n;
		while (ptr != ptr2)
			cin >> *ptr++;

		--ptr;

		while (ptr + 1 != d)
			cout << *ptr-- << " ";

		cout << endl;
	}

	return 0;
}
