#include <iostream>

using namespace std;

int main()
{
	char c;
	bool uc = false;

	while (cin.get(c))
	{
		if (c == ' ')
			uc = true;
		else
			if (uc)
			{
				if (c >= 'a' && c <= 'z')
					cout << char(c - 'a' + 'A');
				else
					cout << c;
				uc = false;
			}
			else
				cout << c;
	}

	return 0;
}
