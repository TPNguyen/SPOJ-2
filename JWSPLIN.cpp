#include <iostream>

using namespace std;

int main()
{
	int t, x1, y1, x2, y2, x3, y3;

	cin >> t;

	while (t--)
	{
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		cout << ((y3-y1)*(x1-x2)==(y1-y2)*(x3-x1)?"TAK":"NIE") << endl;
	}

	return 0;
}
