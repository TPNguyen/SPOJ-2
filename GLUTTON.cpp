#include <iostream>

using namespace std;

int main()
{
	int t, n, m, o, c, p;

	cin >> t;

	while (t--)
	{
		cin >> n >> m;		
		c = 0;
		while (n--)
		{
			cin >> o;
			c += 86400 / o;
		}
		p = c/m;
		if (p * m < c)
			++p;
		cout << p << endl;
	}
	
	return 0;
}
