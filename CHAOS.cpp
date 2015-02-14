#include <iostream>
#include <iomanip>

using namespace std;

class Time
{
public:
	int g, m;
};

bool palindrom(Time);
void incTime(Time &);

int main()
{
	char ignore;
	int n;
	Time t;

	cin >> n;

	while (n--)
	{
		cin >> t.g >> ignore >> t.m;

		do 
		{
			incTime(t);
		} while (!palindrom(t));

		cout << setw(2) << setfill('0') << t.g << ":" << setw(2) << setfill('0') << t.m << endl;
	}

	return 0;
}

bool palindrom(Time t)
{
	if (t.g > 23 || t.m > 59)
		return false;
	if (t.g == 0)
	{
		if (t.m <= 9 || !(t.m % 11))
			return true;
		return false;
	}
	if (t.g < 10)
		if (t.m % 10 == t.g)
			return true;
		else
			return false;
	if (t.m == t.g % 10 * 10 + t.g / 10)
		return true;
	return false;
}

void incTime(Time &t)
{
	++t.m;
	if (t.m > 59)
	{
		t.m = 0;
		++t.g;
		if (t.g > 23)
			t.g = 0;
	}
}
