#include <iostream>

using namespace std;

int main()
{
	char c;

	while (cin.get(c))
	{
		if (c <= 'Z' && c >= 'A')
		{
			c += 3;
			if (c > 'Z')
				c = c - 'Z' + 'A' - 1;
		}
		cout << c;
	}
	
	return 0;
}
