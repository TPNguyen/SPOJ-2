#include <iostream>
#include <string>

using namespace std;

string revString(string);

int main()
{
	string input;

	while (cin >> input)
		cout << revString(input) << endl;

	return 0;
}

string revString(string s)
{
	if (s.length() <= 1)
		return s;
	else
		return s[s.length() - 1] + revString(s.substr(1, s.length() -2)) + s[0];
}
