#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

int palindrom(int);
string revString(string);

int main()
{
	int n, g, m;
	int ng, nm;
	char ignore;

	cin >> n;

	while (n--)
	{
		cin >> g >> ignore >> m;
		ng = g;
		// Tutaj trzeba >9 uwzglednic:
		if (0 == g)
			nm = nm + 1;
		else
		// Tutaj trzeba uwzglednic ze dla 01 = 10 a nie 1:
			nm = palindrom(g);
		if (nm <= m || nm > 60)
		{
			ng = g+1;
			if (ng >= 24)
				ng = 0;
			nm = palindrom(ng);
		}
		cout << setw(2) << setfill('0') << ng << ":" << setw(2)
			<< setfill('0') << nm << endl;
	}

	return 0;
}

int palindrom(int a)
{
	stringstream ss;
	string num;

	ss << a;
	ss >> num;
	num = revString(num);
	ss.str(string());
	ss.clear();
	ss << num;
	ss >> a;
	return a;
}

string revString(string str)
{
	if (str.length() > 1)
		return str[str.length()-1] + revString(str.substr(1,str.length()-2)) + str[0];
	else
		return str;
}
