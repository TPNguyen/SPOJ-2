#include <iostream>

using namespace std;

inline int abs(int);

class Point
{
public:
	int x, y;
	int distanceSq(Point);
};

class Circle
{
public:
	Point center;
	int radius;
	int radiusSq() {return radius * radius;}
};

int main()
{
	Circle circle;
	Point point;
	int t;

	cin >> circle.center.x >> circle.center.y >> circle.radius;

	cin >> t;

	while (t--)
	{
		cin >> point.x >> point.y;

		if (point.distanceSq(circle.center) > circle.radiusSq())
			cout << "O" << endl;
		else if (point.distanceSq(circle.center) < circle.radiusSq())
			cout << "I" << endl;
		else if (point.distanceSq(circle.center) == circle.radiusSq())
			cout << "E" << endl;
	}

	return 0;
}

inline int abs(int a)
{
	return a >= 0 ? a : -a;
}

int Point::distanceSq(Point p)
{
	return abs(x-p.x) * abs(x-p.x)  + abs(y-p.y) * abs(y-p.y);
}
