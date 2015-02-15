#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>

using namespace std;

int main()
{
	int t;
	int n;
	int output = 0;
	int input;

	cin >> t;

	for (int i=0; i<t; ++i)
	{
		cin >> n;
		for (int k=0; k<n; ++k)
		{
			cin >> input;
			output += input;
		}
		cout << output << endl;
		output = 0;
	}

	return 0;
}