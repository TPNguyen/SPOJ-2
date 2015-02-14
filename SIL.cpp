#include <iostream>

using namespace std;

class Point
{
public:
	int x, y;
	Point() {;}
	Point(int, int);
};

class Rectangle
{
public:
	Rectangle() {;}
	Rectangle(Point, Point);
	int area();
	Point leftLower();
	Point rightUpper();
	Rectangle overlaping(Rectangle);
private:
	Point leftLowerCorner, rightUpperCorner;
};

istream &operator>>(istream &, Point &);

int main()
{
	Point a, b, c, d;
	Rectangle r1, r2;
	
	while (cin >> a >> b >> c >> d)
	{
		r1 = Rectangle(a, b);
		r2 = Rectangle(c, d);

		cout <<  r1.area() + r2.area() - r1.overlaping(r2).area();
		cout << endl;
	}

	return 0;
}

Point::Point(int a, int b)
{
	x = a;
	y = b;
}

Rectangle::Rectangle(Point a, Point b)
{
	leftLowerCorner = a;
	rightUpperCorner = b;
}

int Rectangle::area()
{
	int a = rightUpperCorner.x - leftLowerCorner.x;
	int b = rightUpperCorner.y - leftLowerCorner.y;

	return a * b;
}

Rectangle Rectangle::overlaping(Rectangle rectangle)
{
	Rectangle *right, *left;
	Rectangle *upper, *lower;
	int x1, y1, x2, y2;
	
	//a co jak sie zawiera jeden w drugim?

	if (leftLowerCorner.x < rectangle.leftLowerCorner.x)
	{
		left = this;
		right = &rectangle;
	}
	else
	{
		left = &rectangle;
		right = this;
	}

	if (left->rightUpperCorner.x < right->leftLowerCorner.x)
		return Rectangle(Point(0,0), Point(0,0));
	else
	{
		x1 = right->leftLowerCorner.x;
		if (left->rightUpperCorner.x < right->rightUpperCorner.x)
			x2 = left->rightUpperCorner.x;
		else
			x2 = right->rightUpperCorner.x; 
	}

	if (leftLowerCorner.y < rectangle.leftLowerCorner.y)
	{
		lower = this;
		upper = &rectangle;
	}
	else
	{
		lower = &rectangle;
		upper = this;
	}

	if (lower->rightUpperCorner.y < upper->leftLowerCorner.y)
		return Rectangle(Point(0,0), Point(0,0));
	else
	{
		y1 = upper->leftLowerCorner.y;
		if (lower->rightUpperCorner.y < upper->rightUpperCorner.y)
			y2 = lower->rightUpperCorner.y;
		else
			y2 = upper->rightUpperCorner.y;
	}

	return Rectangle(Point(x1,y1), Point(x2,y2));
}

istream &operator>>(istream & in, Point &p)
{
	int a, b;

	in >> a >> b;
	p = Point(a, b);
	return in;
}
