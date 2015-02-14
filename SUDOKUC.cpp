#include <iostream>

using namespace std;

int main()
{
	int n;
	int sudoku[9][9];
	int temp[9];
	int i, j, k, l, t;
	bool correct;
	
	cin >> n;

	while (n--)
	{
		correct = true;

		for (i = 0; i < 9; ++i)
			for (j = 0; j < 9; ++j)
			{
				cin >> sudoku[i][j];
				// sprawdzenie czy wartosc jest w prawidlowym zakresie:
				if (sudoku[i][j] > 9 || sudoku[i][j] < 0)
					correct = false;
			}

		// sprawdzenie czy zadna wartosc w danym wierszu sie nie powtarza:
		// (w tych forach mozna byc dac warunek od correct
		// zeby przyspieszyc program)
		if (correct)
			for (i = 0; i < 9; ++i)
				for (j = 0; j < 9; ++j)
					for (k = j + 1; k < 9; ++k)
						if (sudoku[i][j] == sudoku[i][k])
							correct = false;

		// ...oraz w zadnej kolumnie:
		if (correct)
			for (j = 0; j < 9; ++j)
				for (i = 0; i < 9; ++i)
					for (k = i + 1; k < 9; ++k)
						if (sudoku[i][j] == sudoku[k][j])
							correct = false;

		// ...oraz w zadnym bloku 3x3:
		if (correct)
			// przejscie po 9 blokach 3x3:
			for (k = 0; k < 9; k += 3)
				for (l = 0; l < 9; l += 3)
				{
					// rozwiniecie bloku w jedna tablice 9 elementow:
					t = 0;
					for (i = 0; i < 3; ++i)
						for (j = 0; j < 3; ++j)
							temp[t++] = sudoku[k + i][l + j];
					// sprawdzenie czy w tej tablicy
					// nie ma powtarzajacych sie elementow:
					for (i = 0; i < 9; ++i)
						for (j = i + 1; j < 9; ++j)
							if (temp[i] == temp[j])
								correct = false;
				}

		if (correct)
			cout << "TAK" << endl;
		else
			cout << "NIE" << endl;
	}

	return 0;
}
