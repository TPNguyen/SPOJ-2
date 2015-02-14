#include <iostream>
#include <vector>

using namespace std;

class Kab
{
public:
	int num(char);
	void push_back(char, int);
	struct kabEntry
	{
		char symbol;
		int value;
	};
private:
	vector<kabEntry> entries;
};

int main()
{
	char c;
	int ret = 0;
	Kab kab;

	kab.push_back('a' , 1);
	kab.push_back('b' , 2);
	kab.push_back('c' , 3);
	kab.push_back('d' , 4);
	kab.push_back('e' , 5);
	kab.push_back('f' , 6);
	kab.push_back('g' , 7);
	kab.push_back('h' , 8);
	kab.push_back('i' , 9);
	kab.push_back('k' , 10);
	kab.push_back('l' , 20);
	kab.push_back('m' , 30);
	kab.push_back('n' , 40);
	kab.push_back('o' , 50);
	kab.push_back('p' , 60);
	kab.push_back('q' , 70);
	kab.push_back('r' , 80);
	kab.push_back('s' , 90);
	kab.push_back('t' , 100);
	kab.push_back('v' , 200);
	kab.push_back('x' , 300);
	kab.push_back('y' , 400);
	kab.push_back('z' , 500);

	while (cin.get(c))
	{
		ret += kab.num(c);
	}

	cout << ret << endl;

	return 0;
}

int Kab::num(char c)
{
	for (vector<kabEntry>::iterator it = entries.begin(); it !=entries.end(); ++it)
		if (it->symbol == c)
			return it->value;
	return 0;
}

void Kab::push_back(char c, int n)
{
	kabEntry entry;
	entry.symbol = c;
	entry.value = n;
	entries.push_back(entry);
}
