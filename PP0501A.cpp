#include <iostream>

using namespace std;

int nwd(int a, int b);

int main()
{
	int t, a, b;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cin >> a;
		cin >> b;
		cout << nwd(a, b) << endl;
	}
	return 0;
}

int nwd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return nwd(b, a%b);
}
