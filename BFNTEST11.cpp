#include <iostream>

using namespace std;

int main()
{
	char symbol, temp;
	bool lineComment = false;
	bool blockComment = false;
	bool cString = false;
	
	while (cin.get(symbol))
	{
		if (lineComment)
		{
			if (symbol == '\n')
			{
				lineComment = false;
				cout << symbol;
			}
		}
		else if (blockComment)
		{
			while (symbol == '*')
			{
				if (cin.get(symbol))
				{
					if (symbol == '/')
						blockComment = false;
				}
				else
					break;
			}
		}
		else
		{
			if (cString)
			{
				cout << symbol;
				if ((symbol == '"' && symbol != '\\') || (symbol == '\n' && temp != '\\'))
					cString = false;
			}
			else
			{
				if (symbol == '/')
				{
					temp = symbol;
					if (cin.get(symbol))
					{
						if (symbol == '/')
						{
							lineComment = true;
						}
						else if (symbol == '*')
						{
							blockComment = true;
						}
						else
						{
							cout << temp << symbol;
						}
					}
					else
					{
						cout << temp;
						break;
					}
				}
				else
				{
					if (symbol == '"' && temp != '\'')
						cString = true;
					cout << symbol;
				}
			}
		}
		temp = symbol;
	}
	
	return 0;
}
