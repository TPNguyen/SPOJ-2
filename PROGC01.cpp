#include <iostream>
#include <string>

using namespace std;

int main()
{
	int i = 0;
	string s;

	while (getline(cin, s)) ++i;

	cout << i << endl;

	return 0;
}
