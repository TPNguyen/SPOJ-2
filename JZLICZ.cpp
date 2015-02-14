#include <iostream>

using namespace std;

int main()
{
	int t;
	char s;
	int *a = new int['Z'-'A'+'z'-'a'+2]();
	
	cin >> t;

	while (cin >> s)
	{
		if (s >= 'a' && s <= 'z')
			++a[s-'a'];
		else if (s >= 'A' && s <= 'Z')
			++a[s-'A'+'z'+1-'a'];
	}

	for (int i = 0; i < 'Z'-'A'+'z'-'a'+2; ++i)
		if (a[i] != 0)
			if (i <= 'z'-'a')
				cout << (char) (i + 'a') << " " << a[i] << endl;
			else
				cout << (char) (i - 'z' + 'a' + 'A' - 1) << " " << a[i] << endl;

	delete[] a;
	
	return 0;
}
