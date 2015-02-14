#include <iostream>

using namespace std;

int main()
{
	int ascii[256] = {0};
	char c;
	
	while (cin.get(c))
		++ascii[(unsigned char) c];

	for (int i = 0; i < 256; ++i)
		if (ascii[i] > 0)
			cout << i << " " << ascii[i] << endl;

	return 0;
}
