#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t;
	string input;

	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		cin >> input;
		cout << input.substr(0, input.length() / 2) << endl;
	}

	return 0;
}
