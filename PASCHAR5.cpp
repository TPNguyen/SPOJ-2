#include <iostream>

using namespace std;

int main()
{
	char c;

	while (cin.get(c))
	{
		if (c >= 'A' && c <= 'Z')
		{
			c += 13;
			if (c > 'Z')
				c -= ('Z' - 'A' + 1);
		}
		else if (c >= 'a' && c <= 'z')
		{
			c -= 13;
			if (c < 'a')
				c += ('z' - 'a' + 1);
		}
		else if (c >= '0' && c <= '9')
		{
			c += 5;
			if (c > '9')
				c -= ('9' - '0' + 1);
		}
		cout << c;
	}

	return 0;
}
