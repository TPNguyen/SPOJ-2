#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class indexedValue
{
public:
	string i;
	int index;
	int less;
	indexedValue();
	indexedValue(string, int);
	/*
	bool operator<(indexedValue other)
	{
		return lessThan(other.i, i);
	}
	*/
};

indexedValue::indexedValue()
{
	less = 0;
}

indexedValue::indexedValue(string s, int in)
{
	less = 0;
	i = s;
	index = in;
}

void show(vector<indexedValue>);
bool lessThan(string, string);
bool lessThanIVi(indexedValue, indexedValue);
bool lessThanIVindex(indexedValue, indexedValue);

int main()
{
	vector<string> A;
	vector<indexedValue> I;
	indexedValue inputIV;
	string input;
	int n, k, i;
	
//wczytanie i posortowanie zbioru A:
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> input;
		A.push_back(input);
	}
	sort(A.begin(), A.end(), lessThan);

	cin >> k;

	vector<string>::iterator it;

	while (k--)
	{
		cin >> input;
		it = A.begin();
		while (it!=A.end() && lessThan(*it, input))
			++it;
		cout << it - A.begin() << endl;
	}
/*
//wczytanie i posortowanie zbioru I:
	cin >> k;
	for (int i = 0; i < k; ++i)
	{
		cin >> input;
		inputIV = indexedValue(input, i);
		I.push_back(inputIV);
	}
	sort(I.begin(), I.end(), lessThanIVi);

//Tutaj zrobic porownanie:
	vector<string>::iterator itA = A.begin();
	
	for (vector<indexedValue>::iterator it = I.begin(); it != I.end();)
	{
		while(lessThan((*itA), (*it).i))
		{
			(*it).less += 1;
			++itA;
			// niech sie nie przepelnia itA
		}
		++it;
		(*it).less = (*(it-1)).less;
	}

//Odsortowanie i wypisanie zbioru I:
	sort(I.begin(), I.end(), lessThanIVindex);
	show(I);
*/

	return 0;
}

bool lessThan(string a, string b)
{
	// a < b = true;
	if (a.length() < b.length())
		return true;
	else if (a.length() > b.length())
		return false;
	else
	{
		int i = 0;
		
		while (i < a.length())
			if (a[i] < b[i])
				return true;
			else if (a[i] > b[i])
				return false;
			else
				++i;

		return false;
	}
}

bool lessThanIVi(indexedValue a, indexedValue b)
{
	return lessThan(a.i, b.i);
}

bool lessThanIVindex(indexedValue a, indexedValue b)
{
	return a.index < b.index;
}

void show(vector<indexedValue> vec)
{
	for (vector<indexedValue>::iterator it = vec.begin(); it != vec.end(); ++it)
		cout << (*it).less << endl;
}
