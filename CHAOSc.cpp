#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

int palindrom(int);
bool palindrom(char *, char *);
string revString(string);

int main()
{
	int n;
	char ignore;
	char g[3], m[3];

	cin >> n;

	while (n--)
	{
		cin >> setw(3) >> g >> ignore >> setw(3) >> m;

		while (1)
		{
			if (g[1] == '0' && g[0] == '0')
			{
				if (m[0] == '0' && m[1] != '9')
				{
					++m[1];
					break;
				}
				else if (m[0] == '0')
				{
					m[0] = '1';
					m[1] = '1';
					break;
				}
				if (m[1] == '9')
				{
					if (m[0] != '5')
					{
						++m[0];
						m[1] = m[0];
						break;
					}
					else
					{
						g[1] = '1';
						m[0] = '0';
						m[1] = '1';
						break;
					}
				}
				else if (m[1] > m[0])
				{
					m[0] = m[1];
					break;
				}
			}
			if (g[0] == '0')
			{
				if (m[0] == '5' && m[1] == '9')
				{
					++g[1];
					if (g[1] > '9')
					{
						g[0] = '1';
						g[1] = '0';
						m[0] = '0';
						m[1] = '1';
						break;
					}
					m[0] = '0';
					m[1] = g[1];
					break;
				}
				if (m[1] >= g[1])
					++m[0];
				m[1] = g[1];
				break;
			}
			else
			{
				if ( ((m[0] < g[1]) || (m[0] == g[1] && m[1] < g[0]) )&& (g[1] < '6'))
				{
					m[0] = g[1];
					m[1] = g[0];
					break;
				}
				else
				{

					++g[1];
					if (g[1] > '9')
					{
						g[0] = '2';
						g[1] = '0';
						m[0] = '0';
						m[1] = '2';
					}
					m[0] = '0';
					m[1] = '0';
					if (g[0] == '2' && g[1] > '3')
					{
						g[0] = '0';
						g[1] = '0';
						m[0] = '0';
						m[1] = '0';
						break;
					}
				}
			}
		}
		cout << g << ":" << m << endl;
	}


	return 0;
}


int palindrom(int a)
{
	stringstream ss;
	string num;

	ss << a;
	ss >> num;
	num = revString(num);
	ss.str(string());
	ss.clear();
	ss << num;
	ss >> a;
	return a;
}

string revString(string str)
{
	if (str.length() > 1)
		return str[str.length()-1] + revString(str.substr(1,str.length()-2)) + str[0];
	else
		return str;
}

bool palindrom(char *a, char *b)
{
	return false;
}
