#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	size_t pos;
	char c;

	while (getline(cin, input))
	{
		pos = 0;
		while ((pos = input.find("??", pos)) != string::npos)
		{
			if (pos + 2 < input.length())
			{
				c = input.at(pos + 2);
				switch (c)
				{
				case '=':
					input.replace(pos, 3, 1,'#');
					break;
				case '/':
					input.replace(pos, 3, 1,'\\');
					break;
				case '\'':
					input.replace(pos, 3, 1,'^');
					break;
				case '(':
					input.replace(pos, 3, 1,'[');
					break;
				case ')':
					input.replace(pos, 3, 1,']');
					break;
				case '!':
					input.replace(pos, 3, 1,'|');
					break;
				case '<':
					input.replace(pos, 3, 1,'{');
					break;
				case '>':
					input.replace(pos, 3, 1,'}');
					break;
				case '-':
					input.replace(pos, 3, 1,'~');
					break;
				default:
					++pos;
				}
			}
		}
		cout << input << endl;
	}

	return 0;
}
