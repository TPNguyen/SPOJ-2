#include <iostream>
#include <string>

using namespace std;

class Array2D;
ostream & operator<<(ostream &, Array2D &);

class Array2D
{
private:
	int m, n;
	char **array;
public:
	Array2D(int, int);
	~Array2D();
	void rotL(void);
	void set(char, int, int);
	friend ostream & operator<<(ostream &, Array2D &);
	char get(int, int);
};

int main()
{
	int t, l, k, row, col;
	int value;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		cin >> l >> k;
		Array2D tablica(l, k);
		for (row = 0; row < l; ++row)
			for (col = 0; col < k; ++col)
			{
				cin >> value;
				tablica.set(value, row, col);
			}
		tablica.rotL();
		cout << tablica;
	}

	return 0;
}

Array2D::Array2D(int row, int col)
{
	m = row;
	n = col;
	array = new char *[m];
	for (int i = 0; i < m; ++i)
		array[i] = new char[n];
}

Array2D::~Array2D()
{
	for (int i = 0; i < m; ++i)
		delete [] array[i];
	//delete [] *array;
	delete [] array;
}

void Array2D::rotL(void)
{
	int first = get(0,0);	
	for (int i = 0; i < n - 1; ++i)
		set(get(0, i+1), 0, i);
	for (int i = 0; i < m - 1; ++i)
		set(get(i+1, n-1), i, n-1);
	for (int i = n-1; i > 0; --i)
		set(get(m-1, i-1), m-1, i);
	for (int i = m-1; i > 1; --i)
		set(get(i-1, 0), i, 0);
	set(first, 1, 0);
}

ostream & operator<<(ostream &strumien_wyj, Array2D &array)
{	
	int i, j;

	for (i = 0 ; i < array.m; ++i)
	{
		for (j = 0; j < array.n; ++j)
			strumien_wyj << int(array.get(i, j)) << " ";
		strumien_wyj << endl;
	}

	return strumien_wyj;
}

char Array2D::get(int row, int col)
{
	if (row < m && col < n)
		return  (array[row])[col];
	return 0;
}

void Array2D::set(char value, int row, int col)
{
	if (row < m && col < n)
		(array[row])[col] = value;
}
