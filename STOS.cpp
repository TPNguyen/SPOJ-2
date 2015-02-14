#include <iostream>

using namespace std;

int main()
{
	int heap[10];
	int i = 0;
	char command;
	int value;

	while (cin >> command)
	{
		switch (command)
		{
		case '+':
			cin >> value;
			if (i >= 10)
				cout << ":(" << endl;
			else
			{
				heap[i++] = value;
				cout << ":)" << endl;
			}
			break;
		case '-':
			if (i <= 0)
				cout << ":(" << endl;
			else
				cout << heap[--i] << endl;
			break;
		}
	}

	return 0;
}
