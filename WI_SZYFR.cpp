#include <iostream>
#include <string>
// sprawdzic czy dobrze zamienia jak przekroczy 'Z' albo 'A'
// sprawdzic skrajne przypadki (1 literka itp.)

using namespace std;

class Gronsfeld
{
public:
	string encrypt(string);
	string decrypt(string);
	string key;
};

string removeLeading(string, char);

int main()
{
	string mode, key, text;
	Gronsfeld code;

	cin >> mode >> key >> text;

	// ?? pomijanie 0 na poczatku klucza
	code.key = removeLeading(key, '0');

	if (!mode.compare("SZYFRUJ"))
		cout << code.encrypt(text) << endl;
	else if (!mode.compare("DESZYFRUJ"))
		cout << code.decrypt(text) << endl;

	return 0;
}

string Gronsfeld::encrypt(string input)
{
	if (key == string())
		return input;

	size_t iKey = 0, iText;
	string result = input;

	for (iText = 0; iText < result.length(); ++iText)
	{
		result[iText] += key[iKey++] - '0';

		if (iKey >= key.length())
			iKey = 0;

		if (result[iText] > 'Z')
			result[iText] -= ('Z' - 'A' + 1);
	}

	return result;
}

string Gronsfeld::decrypt(string input)
{
	if (key == string())
		return input;

	size_t iKey = 0, iText;
	string result = input;

	for (iText = 0; iText < result.length(); ++iText)
	{
		result[iText] -= key[iKey++] - '0';

		if (iKey >= key.length())
			iKey = 0;

		if (result[iText] < 'A')
			result[iText] += ('Z' - 'A' + 1);
	}

	return result;
}

string removeLeading(string input, char c)
{
	size_t i = 0;
	while (input[i] == c)
		++i;

	return input.substr(i, string::npos);
}
