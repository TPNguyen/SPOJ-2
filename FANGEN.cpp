#include <iostream>

using namespace std;

class Fan
{
public: 
	Fan(int);
	~Fan();
	friend ostream &operator<<(ostream &, const Fan &);
private:
	char **f;
	int r;
	bool dir;
	void fill(int, int = 0, int = 0);
};

int main()
{
	int r;
	cin >> r;
	while (r != 0)
	{
		Fan fan(r);
		cout << fan << endl;
		cin >> r;
	}

	return 0;
}

ostream &operator<<(ostream &out, const Fan &fan)
{
	for (int i = 0; i < 2*fan.r; ++i)
	{
		for (int j = 0; j < 2*fan.r; ++j)
			out << fan.f[i][j];
		out << endl;
	}

	return out;
}

Fan::Fan(int rz)
{
	if (rz >= 0)
	{
		r = rz;
		dir = true;
	}
	else
	{
		r = -rz;
		dir = false;
	}
	//alokacja tablicy 2rz x 2rz
	f = new char *[2*r];
	for (int i = 0; i < 2*r; ++i)
		f[i] = new char[2*r];
	//wypelnienie tablicy
	fill(r);
}

Fan::~Fan()
{
	//zwolnienie tablicy 2rz x 2rz
	for (int i = 0; i < 2*r; ++i)
		delete[] f[i];
	delete[] f;
}

void Fan::fill(int cr, int si, int sj)
{
	int i = si;
	int j = sj;

	f[i][j++] = '*';
	for (int n = 0; n < cr -1; ++n)
		f[i][j++] = dir?'.':'*';
	for (int n = 0; n < cr -1; ++n)
		f[i][j++] = (!dir)?'.':'*';

	f[i++][j] = '*';
	for (int n = 0; n < cr -1; ++n)
		f[i++][j] = dir?'.':'*';
	for (int n = 0; n < cr -1; ++n)
		f[i++][j] = (!dir)?'.':'*';
	
	f[i][j--] = '*';
	for (int n = 0; n < cr -1; ++n)
		f[i][j--] = dir?'.':'*';
	for (int n = 0; n < cr -1; ++n)
		f[i][j--] = (!dir)?'.':'*';

	f[i--][j] = '*';
	for (int n = 0; n < cr -1; ++n)
		f[i--][j] = dir?'.':'*';
	for (int n = 0; n < cr -1; ++n)
		f[i--][j] = (!dir)?'.':'*';

	if (cr > 1)
		fill(cr - 1, si + 1, sj + 1);
}
