#include <iostream>

using namespace std;

int keypadNum(char);

int main()
{
	int t;
	char c;

	cin >> t;

	cin.get(); // '\n'

	while (t--)
	{
		while ((c = cin.get()) != '\n')
			cout << keypadNum(c);
		cout << endl;
	}

	return 0;
}

int keypadNum(char c)
{
	if (c >= 'A' && c <= 'C')
		return 2;
	else if (c >= 'D' && c <= 'F')
		return 3;
	else if (c >= 'G' && c <= 'I')
		return 4;
	else if (c >= 'J' && c <= 'L')
		return 5;
	else if (c >= 'M' && c <= 'O')
		return 6;
	else if (c >= 'P' && c <= 'S')
		return 7;
	else if (c >= 'T' && c <= 'V')
		return 8;
	else if (c >= 'W' && c <= 'Z')
		return 9;
	else
		return 0;
}
