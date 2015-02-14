#include <iostream>

using namespace std;

int main()
{
	int l = 0, w = 0;
	char c;
	bool word = false;

	while(cin.get(c))
	{
		if (c == ' ' || c == '\n')
		{
			if (word)
				++w;
			else
			    	++l;

			if (c == '\n')
			{
				cout << l << " " << w << endl;
				l = w = 0;
			}
			word = false;
		}
		else if (c < '0' || c > '9')
			word = true;
	}

	return 0;
}
