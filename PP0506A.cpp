#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Point
{
public:
	string name;
	int x, y, dsq;
};

bool comp(const Point &, const Point &);

int main()
{
	int t, n;
	Point point;
	vector<Point> vec;
	
	cin >> t;

	while (t--)
	{
		cin >> n;
		while (n--)
		{
			cin >> point.name >> point.x >> point.y;
			point.dsq = point.x * point.x + point.y * point.y;
			vec.push_back(point);
		}
		sort(vec.begin(), vec.end(), comp);
		for (vector<Point>::iterator it = vec.begin(); it != vec.end(); ++it)
		{
			cout << (*it).name << " " << (*it).x << " ";
			cout << (*it).y << endl;
		}
		cout << endl;
		vec.clear();
	}

	return 0;
}

bool comp(const Point &p1, const Point &p2)
{
	return (p1.dsq <= p2.dsq);
}
