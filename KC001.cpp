#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>

using namespace std;

int main()
{
	int sum = 0;
	int a;
	for (int i=0; i<3; ++i)
	{
		cin >> a;
		sum += a;
	}
	cout << sum;
	return 0;
}