#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int lessThan(const char[32], const char[32]);

int main()
{
	char (*A)[32]; //A jest wskaznikiem na tablice 32 charow
	int n, k, i;
	
//wczytanie i posortowanie zbioru A:
	cin >> n;
	A = new char[n][32];
	for (int i = 0; i < n; ++i)
		cin >> A[i];
	
	qsort(A, n, sizeof(A[0]), lessThan);

	for (int i = 0; i < n; ++i)
		cout << A[i] << endl;


	delete[] A;
	return 0;
}

int lessThan(const char *a, const char *b)
{
	// a < b = true;
	if (strlen(a) < strlen(b))
		return 1;
	else if (strlen(a) > strlen(b))
		return 0;
	else
	{
		int i = 0;
		
		while (i < strlen(a))
			if (a[i] < b[i])
				return true;
			else if (a[i] > b[i])
				return false;
			else
				++i;

		return 0;
	}
}
