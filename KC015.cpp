#include <iostream>
#include <string>

using namespace std;

void equalLength(string &, string &);

int main()
{
	string a, b, op;
	
	while (cin >> a >> op >> b)
	{
		equalLength(a, b);
		if (!op.compare("=="))
			cout << (a == b) << endl;
		else if (!op.compare("!="))
			cout << (a != b) << endl;
		else if (!op.compare(">="))
			cout << (a >= b) << endl;
		else if (!op.compare("<="))
			cout << (a <= b) << endl;
	}

	return 0;
}

void equalLength(string &a, string &b)
{
	if (a.length() > b.length())
		b = string(a.length() - b.length(), '0') + b;
	else
		a = string(b.length() - a.length(), '0') + a;
}
