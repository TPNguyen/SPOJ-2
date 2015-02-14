#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

bool validName(string);
bool RRRRValid(int);
bool MMValid(int);
bool DDValid(int);
string between(string input, string before, string after);
int stringToInt(string input);
int readNumber(string input);
void getDate(string date, int &RRRR , int &MM, int &DD);

int main()
{
	int RRRR, MM, DD;
	string imie, nazwisko;
	string input;
	string data;

	while (getline(cin, input))
	{
		imie = between(input, "Imie: ", ";");
		nazwisko = between(input, "Nazwisko: ", ";");
		data = input.substr(input.find("Data ur.: ") + string("Data ur.: ").length(), string::npos);
		getDate(data, RRRR, MM, DD);

		if (!validName(imie))
			cout << 0 << endl;
		else if (!validName(nazwisko))
			cout << 1 << endl;
		else if (!(RRRRValid(RRRR) && MMValid(MM) && DDValid(DD)))
			cout << 2 << endl;
		else
			cout << 3 << endl;
	}

	return 0;
}

bool validName(string name)
{
	if (!isupper(name[0]))
		return false;
	for (int i = 1; i < name.length(); ++i)
		if (!islower(name[i]))
			return false;

	return true;
}

bool RRRRValid(int RRRR)
{
	return (RRRR >= 1900 && RRRR <= 2000);
}

bool MMValid(int MM)
{
	return (MM >= 1 && MM <= 12);
}

bool DDValid(int DD)
{
	return (DD >= 1 && DD <= 31);
}

string between(string input, string before, string after)
{
	size_t start = input.find(before) + before.length();
	size_t end = input.find(after, start);

	return input.substr(start, end - start);
}

int stringToInt(string input)
{
	int ret;
	
	stringstream ss;
	ss << input;
	ss >> ret;

	return ret;
}

int readNumber(string input)
{
	string number;
	int i = 0;

	while (input[i] >= '0' && input[i] <= '9')
	{
		number += input[i];
		++i;
	}

	return stringToInt(number);
}

void getDate(string date, int &RRRR , int &MM, int &DD)
{
	int i = 0;

	RRRR = readNumber(date);
	while (date[i] >= '0' && date[i] <= '9')
		++i;
	++i;
	MM = readNumber(date.substr(i, string::npos));
	while (date[i] >= '0' && date[i] <= '9')
		++i;
	++i;
	DD = readNumber(date.substr(i, string::npos));
}
