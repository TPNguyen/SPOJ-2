#include <iostream>

using namespace std;

int main()
{
	char c, remove;

	while (cin.get(remove))
	{
		cin.get(c); // spacja
		while (cin.get(c))
		{
			if (c != remove)
				cout << c;
			if (c == '\n')
				break;
		}
	}

	return 0;
}
