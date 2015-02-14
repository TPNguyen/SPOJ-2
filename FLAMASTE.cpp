#include <iostream>

using namespace std;

int main()
{
	char a, ap;
	int i;
	cin >> i;
	i = 0;

	cin.get(ap);
	while (cin.get(a))
	{
		if (a != ap)
			if (i == 0)
				cout << ap;
			else if (i == 1)
			{
				cout << ap << ap;
				i = 0;
			}
			else
			{
				cout << ap << i + 1;
				i = 0;
			}
		else
			++i;	

		ap = a;
	}

	if (i == 0)
		cout << a;
	else if (i == 1)
		cout << a << a;
	else
		cout << a << i + 1;

	return 0;
}
