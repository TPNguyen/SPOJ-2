#include <iostream>

using namespace std;

int main()
{
	int reg[10];
	char c;
	int a, b;

	while (cin >> c >> a >> b)
	{
		switch (c)
		{
		case 'z':
			reg[a] = b;
			break;
		case '+':
			cout << reg[a] + reg[b] << endl;
			break;
		case '-':
			cout << reg[a] - reg[b] << endl;
			break;
		case '*':
			cout << reg[a] * reg[b] << endl;
			break;
		case '/':
			cout << reg[a] / reg[b] << endl;
			break;
		case '%':
			cout << reg[a] % reg[b] << endl;
			break;
		}
	}
	
	return 0;
}
