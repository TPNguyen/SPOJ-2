#include <iostream>

using namespace std;

int main()
{
	char c = 0, c1 = 0;
	bool singleLine = false;
	bool block = false;
	bool doubleQuote = false;
	bool singleQuote = false;

	while (cin.get(c))
	{
		if (singleQuote)
		{
			if ((c == '\n' || c == '\'') && c1 != '\\')
				singleQuote = false;
			cout << c;
		}
		else if (doubleQuote)
		{
			if ((c == '\n' || c == '"') && c1 != '\\')
				doubleQuote = false;
			cout << c;
		}
		else if (singleLine)
		{
			if (c == '\n' && c1 != '\\')
			{
				singleLine = false;
				cout << c;
			}
		}
		else if (block)
		{
			if (c == '/' && c1 == '*')
				block = false;
		}
		else
			if (c == '/')
			{
				c1 = c;
				if (cin.get(c))
					if (c == '/')
						singleLine = true;
					else if (c == '*')
					{
						block = true;
						c = '\0';
					}
					else
						cout << c1 << c;
				else
					return 0;
			}
			else if (c == '\'')
			{
				singleQuote = true;
				cout << c;
			}
			else if (c == '"')
			{
				doubleQuote = true;
				cout << c;
			}
			else
				cout << c;

		c1 = c;
	}
	
	return 0;
}
