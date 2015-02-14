#include <iostream>

using namespace std;

int main()
{
	int d, n, direction, distance, x, y;

	cin >> d;

	while (d--)
	{
		cin >> n;
		x = 0;
		y = 0;
		while (n--)
		{
			cin >> direction >> distance;
			switch (direction)
			{
			case 0:
				y += distance;
				break;
			case 1:
				y -= distance;
				break;
			case 2:
				x += distance;
				break;
			case 3:
				x -= distance;
			}
		}
		if (x == 0 && y == 0)
		{
			cout << "studnia" << endl;
		}
		else
		{
			if (y > 0)
				cout << 0 << " " << y << endl;
			else if (y < 0)
				cout << 1 << " " << -y << endl;
			if (x > 0)
				cout << 2 << " " << x << endl;
			else if (x < 0)
				cout << 3 << " " << -x << endl;
		}
	}

	return 0;
}
