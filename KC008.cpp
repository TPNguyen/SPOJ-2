#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string input;
	long long int a, res, total = 0;
	stringstream ss;

	while (getline(cin, input))
	{
		res = 0;
		ss.clear();
		ss.str(input);
		while (ss >> a)
			res += a;
		cout << res << endl;
		total += res;
	}
	cout << total << endl;

	return 0;
}
