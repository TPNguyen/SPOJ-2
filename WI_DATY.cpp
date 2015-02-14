#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <algorithm>

// dorobic sprawdzanie poprawnosci r,m,d (przestepne itp)

using namespace std;

class Date
{
public:
	string dosfat();
	string iso();
	int dosfat(string);
	int iso(string);
	enum month
	{
		JANUARY = 1,
		FEBRUARY,
		MARCH,
		APRIL,
		MAY,
		JUNE,
		JULY,
		AUGUST,
		SEPTEMBER,
		OCTOBER,
		NOVEMBER,
		DECEMBER
	};
private:
	int d;
	int m;
	int r;
	bool dateCorrect();
};

int pow(int, int);
string decToBin(int);

int main()
{
	Date date;
	string input;

	cin >> input;
	
	if (!date.dosfat(input))
		cout << date.iso() << endl;
	else if (!date.iso(input))
		cout << date.dosfat() << endl;
	else
		cout << "ERROR" << endl;
	
	return 0;
}

int Date::dosfat(string s)
{
	int i;

	// sprawdzenie poprawnosci danych
	if (s.length() != 16)
		return -1;
	for (i = 0; i < s.length(); ++i)
		if (s[i] != '0' && s[i] != '1')
			return -1;
	
	// wyliczenie dnia, miesiaca i roku
	r = 1980;
	for (i = 6; i >= 0; --i)
		r += (s[i] - '0') * pow(2, 6 - i);

	m = 0;
	for (i = 10; i >= 7; --i)
		m += (s[i] - '0') * pow(2, 10 - i);

	d = 0;
	for (i = 15; i >= 11; --i)
		d += (s[i] - '0') * pow(2, 15 - i);

	if (!(m > 0 && m <= 12))
		return -1;

	if (!(d > 0 && m <= 32))
		return -1;

	if (!dateCorrect())
		return -1;

	return 0;
}

string Date::iso()
{
	stringstream ss;

	ss << setw(4) << setfill('0') << r << "-";
	ss << setw(2) << setfill('0') << m << "-";
	ss << setw(2) << setfill('0') << d;

	return ss.str();
	
}

int Date::iso(string s)
{
	int i;
	char ignore;
	stringstream ss;

	// sprawdzenie poprawnosci danych
	if (s.length() != 10)
		return -1;
	i = 0;
	for (; i < 4; ++i)
		if (!isdigit(s[i]))
			return -1;
	if (s[i++] != '-')
		return -1;
	for (; i < 7; ++i)
		if (!isdigit(s[i]))
			return -1;
	if (s[i++] != '-')
		return -1;
	for (; i < 10; ++i)
		if (!isdigit(s[i]))
			return -1;
	ss.str(s);
	ss >> r >> ignore >> m >> ignore >> d;

	if (r > 2017)
		return -1;
	
	if (!dateCorrect())
		return -1;

	return 0;
}

string Date::dosfat()
{
	string res;
	string temp;
	
	res = decToBin(r - 1980);
	if (res.length() < 7)
		res = string(7 - res.length(), '0') + res;
	
	temp = decToBin(m);
	if (temp.length() < 4)
		temp = string(4 - temp.length(), '0') + temp;

	res += temp;

	temp = decToBin(d);
	if (temp.length() < 5)
		temp = string(5 - temp.length(), '0') + temp;

	res += temp;

	return res;
}

bool Date::dateCorrect()
{
	if (m < 1 || d < 1)
		return false;
	
	switch (m)
	{
	case JANUARY:
	case MARCH:
	case MAY:
	case JULY:
	case AUGUST:
	case OCTOBER:
	case DECEMBER:
		if (d > 31)
			return false;
		break;
	case APRIL:
	case JUNE:
	case SEPTEMBER:
	case NOVEMBER:
		if (d > 30)
			return false;
		break;
	case FEBRUARY:
		if ((r%4==0 && r%100!=0) || r%400==0) // 
		{
			if (d > 29)
				return false;
		}
		else
			if (d > 28)
				return false;				
		break;
	default:
		return false;
	}

	return true;
}

int pow(int a, int b)
{
	if (b == 0)
		return 1;

	int res = a;
	for (int i = 1; i < b; ++i)
		res *= a;

	return res;
}

string decToBin(int n)
{
	string res;

	while (n != 0)
	{
		res.append(1, n%2 + '0');
		n /= 2;
	}

	reverse(res.begin(), res.end());

	return res;
}
