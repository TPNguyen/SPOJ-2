#include <iostream>

using namespace std;

int main()
{
	int t, n, l, wiek;

	cin >> t;

	while (t--)
	{
		cin >> n;
		wiek = n - 1;
		while (n --)
		{
			cin >> l;
			wiek += l;
		}
		cout << wiek << endl;
	}
	
	return 0;
}
