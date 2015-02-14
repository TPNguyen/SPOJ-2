#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec;
	vector<int>::iterator it;
	int a;

	while (cin >> a)
		vec.push_back(a);
	it = vec.end();
	while (it != vec.begin())
		cout << *(--it) << " ";
	
	return 0;
}
