#include <iostream>

using namespace std;

int main()
{
	int n, target, number, i;

	while (cin >> target >> n)
	{
		i = 0;
		while (n--)
		{
			cin >> number;
			if (number == target)
				++i;
		}
		cout << i << endl;
	}
	
	return 0;
}
