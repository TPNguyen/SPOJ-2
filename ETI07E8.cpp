#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void show(vector<string>);
vector<string> filter(vector<string> &, size_t, char = '\0', char = '\0', char = '\0', char = '\0');

int main()
{
	int n, k;
	string input;
	vector<string> dict;
	vector<string> res;

	cin >> n >> k;

	while (n--)
	{
		cin >> input;
		dict.push_back(input);
	}
	sort(dict.begin(), dict.end());

	while (k--)
	{
		cin >> input;
		res = dict;
		for (size_t i = 0; i < input.length(); ++i)
		{
			switch (input.at(i))
			{
			case '2':
				res = filter(res, i, 'a', 'b', 'c');
				break;
			case '3':
				res = filter(res, i, 'd', 'e', 'f');
				break;
			case '4':
				res = filter(res, i, 'g', 'h', 'i');
				break;
			case '5':
				res = filter(res, i, 'j', 'k', 'l');
				break;
			case '6':
				res = filter(res, i, 'm', 'n', 'o');
				break;
			case '7':
				res = filter(res, i, 'p', 'q', 'r', 's');
				break;
			case '8':
				res = filter(res, i, 't', 'u', 'v');
				break;
			case '9':
				res = filter(res, i, 'w', 'x', 'y', 'z');
				break;
			}
		}
		show(res);
	}

	return 0;
}

void show(vector<string> vec)
{
	if (!vec.size())
		cout << "BRAK";
	else
		for (vector<string>::iterator it = vec.begin(); it != vec.end(); ++it)
			cout << *it << (it + 1 != vec.end()?" ":"");
	cout << endl;
}

vector<string> filter(vector<string> &vec, size_t pos, char a, char b, char c, char d)
{
	// funkcja zwraca podwektor vec w ktorym
	// kazdy string ma c na pozycji pos

	vector<string> res;

	for (vector<string>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		if (it->length() > pos)
			if (it->at(pos) == a || it->at(pos) == b || it->at(pos) == c || it->at(pos) == d)
				res.push_back(*it);
		//	else if (it->at(pos) > d)
			//	return res;
	}

	return res;
}
