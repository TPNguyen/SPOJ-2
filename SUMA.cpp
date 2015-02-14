#include <iostream>

using namespace std;

int main()
{
	int n, result = 0;
	
	while (cin >> n)
		cout << (result += n) << endl;

	return 0;
}
