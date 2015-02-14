#include <iostream>

using namespace std;

int main()
{
	int n;
	
	cin >> n;
	
	switch (n)
	{
	case 0:
		cout << 0;
		break;
	case 1:
	case 2:
		cout << "NIE";
		break;
	case 3:
		cout << 1 << " " << 3 << " " << 0 << " " << 2;
		break;
	default:
		for (int i = 0; i <= n; ++i)
			cout << (i%2?n/2+(i+1)/2:i/2) << " ";
	}

	return 0;
}
