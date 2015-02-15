#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>

using namespace std;

int main()
{
	int n[2],k[2];
	for (int i=0; i<2; ++i)
	{
		cin >> n[i];
		cin >> k[i];
	}
	cout << (n[0] * k[0] + n[1] * k[1]);
	return 0;
}