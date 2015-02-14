#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
	string input, rev;
	stringstream ss;
	int t, a, b;

	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		cin >> input;
		int j = 0;
		rev = input;
		reverse(rev.begin(), rev.end());
		while (input != rev)
		{
			++j;
			ss.str(string());
			ss.clear();
			ss << input;
			ss >> a;
			ss.str(string());
			ss.clear();
			ss << rev;
			ss >> b;
			ss.str(string());
			ss.clear();
			ss << (a + b);
			input = ss.str();
			rev = input;
			reverse(rev.begin(), rev.end());
		}
		cout << input << " " << j << endl;
	}
	
	return 0;
}
