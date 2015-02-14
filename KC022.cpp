#include <iostream>
#include <cstdio> // EOF
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int k, n, input;
	vector<int> vect;
	char c;
	
	while (cin >> n)
	{
		vect.clear();

		while (cin.peek() != '\n' && cin.peek() != EOF)
		{
			cin >> input;
			vect.push_back(input);
		}

		sort(vect.begin(), vect.end());
		reverse(vect.begin(), vect.end());

		k = 0;

		for (vector<int>::iterator it = vect.begin(); it != vect.end(); ++it)
		{
			if (it > vect.begin())
			{
				if (*it != *(it - 1))	
					++k;
			}
			else
				++k;
			if (k == n)
			{
				cout << *(it) << endl;
				break;
			}
		}
		if (k != n || vect.begin() == vect.end())
			cout << "-" << endl;
	}

	return 0;
}
