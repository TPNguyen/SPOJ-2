#include <iostream>
#include <string>

using namespace std;

string ggPass(string);

int main()
{
	string input;

	while (getline(cin, input))
	{
		cout << ggPass(input) << endl;
	}

	return 0;
}

string ggPass(string s)
{
	string pass;

	for (int i = 0; i < s.length(); i += 2)
	{
		pass += (s[i]-'A')+(s[i+1]-'A')*16;
	}

	return pass;
}
