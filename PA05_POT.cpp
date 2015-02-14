#include <iostream>
#include <string>

using namespace std;

int main()
{
	int D, a, b;
	string input;

	cin >> D;

	for (int i = 0; i < D; ++i)
	{
		cin >> input;
		a = input.at(input.length() - 1) - '0';
		cin >> b;
		switch (a)
		{
		case 0:
			cout << 0;
			break;
		case 1:
			cout << 1;
			break;
		case 2:
			b = b % 4;
			switch (b)
			{
			case 0:
				cout << 6;
				break;
			case 1:
				cout << 2;
				break;
			case 2:
				cout << 4;
				break;
			case 3:
				cout << 8;
			}
			break;
		case 3:
			b = b % 4;
			switch (b)
			{
			case 0:
				cout << 1;
				break;
			case 1:
				cout << 3;
				break;
			case 2:
				cout << 9;
				break;
			case 3:
				cout << 7;
			}
			break;
		case 4:
			b = b % 2;
			switch (b)
			{
			case 0:
				cout << 6;
				break;
			case 1:
				cout << 4;
			}
			break;
		case 5:
			cout << 5;
			break;
		case 6:
			cout << 6;
			break;
		case 7:
			b = b % 4;
			switch (b)
			{
			case 0:
				cout << 1;
				break;
			case 1:
				cout << 7;
				break;
			case 2:
				cout << 9;
				break;
			case 3:
				cout << 3;
			}
			break;
		case 8:
			b = b % 4;
			switch (b)
			{
			case 0:
				cout << 6;
				break;
			case 1:
				cout << 8;
				break;
			case 2:
				cout << 4;
				break;
			case 3:
				cout << 2;
			}
			break;
		case 9:
			b = b % 2;
			switch (b)
			{
			case 0:
				cout << 1;
				break;
			case 1:
				cout << 9;
			}
		}
		cout << endl;
	}

	return 0;
}
