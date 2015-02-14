#include <iostream>

using namespace std;

int main()
{
	char op[2];
	int a, b;

	while (cin >> op)
	{
		cin >> a >> b;
		switch (*op)
		{
		case '+':
			cout << (a + b) << endl;
			break;
		case '-':
			cout << (a - b) << endl;
			break;
		case '*':
			cout << (a * b) << endl;
			break;
		case '/':
			cout << (a / b) << endl;
			break;
		case '%':
			cout << (a % b) << endl;
		}
	}

	return 0;
}
