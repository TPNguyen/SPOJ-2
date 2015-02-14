#include <iostream>

using namespace std;

int main()
{
	int n, k, i;
	int *a;

	cin >> n >> k;

	a = new int[n];

	for (i = 0; i < n; ++i)
		cin >> a[i];
	
	i = k;
	for (int j = 0; j < n; ++j)
	{
		cout << a[i++] << " ";
		if (i >= n)
			i = 0;
	}

	delete [] a;
	
	return 0;
}
