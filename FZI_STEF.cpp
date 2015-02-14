#include <iostream>

using namespace std;

int main()
{
	long long int n, z, aktualna = 0, najwyzsza = 0;

	cin >> n;

	while (n--)
	{
		cin >> z;

		aktualna += z;

		if (aktualna < 0)
			aktualna = 0;

		if (aktualna > najwyzsza)
			najwyzsza = aktualna;
	}

	cout << najwyzsza;

	return 0;
}
