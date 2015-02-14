#include <iostream>

#define abs(x)  (((x)<0)?-(x):(x))

using namespace std;

int main()
{
	int t, n, *a, res;
	float avg;

	cin >> t;

	while (t--)
	{
		cin >> n;
		a = new int[n];
		avg = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
			avg += a[i];
		} 
		avg /= n;
		res = a[0];
		for (int i = 1; i < n; ++i)
			if (abs(a[i]-avg) < abs(res-avg))
				res = a[i];
		cout << res << endl;
	}

	return 0;
}
