#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool lessThan(string, string);

int main()
{
	string *A;
	string input;
	int n, k, i;
	
	cin >> n;

	A = new string[n];

	for (int j = 0; j < n; ++j)
	{
		cin >> input;
		A[j] = input;
	}

	sort(&A[0], &A[n-1], lessThan);

	cin >> k;

	while (k--)
	{
		cin >> input;

		i = 0;
		while (lessThan(A[i], input) && i < n)
				++i;

		cout << i << endl;
	}

	delete[] A;

	return 0;
}

bool lessThan(string a, string b)
{
	// a < b = true;
	if (a.length() < b.length())
		return true;
	else if (a.length() > b.length())
		return false;
	else
	{
		int i = 0;
		
		while (i < a.length())
			if (a[i] < b[i])
				return true;
			else if (a[i] > b[i])
				return false;
			else
				++i;

		return false;
	}
}
