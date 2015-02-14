#include <iostream>
#include <string>

using namespace std;

int howMany5(int);
int pow(int, int);

int main()
{
	int n;
	int k;

	cin >> n >> k;

	do
	{
		++n;
	} while (howMany5(n) < k);

	cout << n << endl;

	return 0;
}

int howMany5(int n)
{
// funkcja zliczajaca wystapienia cyfry 5 w zapisie liczby n
	int i = 1, res = 0;

	while (n > 0)
	{
		if ((n % pow(10,i)) == 5 * pow(10, i-1))
			++res;
		n = n / pow(10,i) * pow(10,i);
		++i;
	}
		
	return res;
}

int pow(int a, int b)
{
// funkcja obliczajaca a do potegi b
	int i;
	int res = a;

	if (b == 0)
		return 1;

	for (i = 1; i < b; ++i)
		res *= a;
	return res;
}

/*
Algorytm:
np. 595 2
start:
595
	dodaje 1 (bo wynik musi byc wyzszy od n)
596
	brakuje jednej 5
	nie ma 5 na pozycji jednosci wiec tam ja ustawie
	ale wtedy liczba bedzie nizsza, wiec zwiekszam liczbe dziesiatek o 1 (59 na 60)
605
	znowu brakuje jednej 5
	na pozycji jednosci jest 5
	na pozycji dziesiatek nie ma wiec tam wstawie.
	Wstawienie powieksza liczbe (bo teraz tam jest 0)
	wiec nie musze robic nic wiecej
655
	koniec.

np. 595 3
595
	zwiekszam o 1
596
	brakuje 5 wiec wstawiam na ostatniej pozycji
	przedostania inkrementuje
605
	brakuje 5 wiec wstawiam na przedostatniej pozycji
655
	nadal brakuje wiec wstawiam na miejscu setek
	to zmniejszy liczbe, wiec inkrementuje cyfre tysiecy
1555
	koniec.
	
np. 476 2
476
	zwiekszam o 1
477
	brakuje 5 wiec wstawiam na pozycji jednosci
	inkrementuje dziesiatki
485
	brakuje 5 wiec wstawiam na miejsce dziesiatek
	ikrementuje setki

	po inkrementacji dostane 5 wiec w to miesjce wstawiam 0
	a 5 daje na setki
555
	jest za duzo 5 wiec moge sprobowac zabrac
	z setek nie zabiore bo bede mial za mala liczbe (455)
	biore z dziesiatek
505
	koniec.

np. 49994 2
49994
	zwiekszam o 1
49995
	jest za malo 5
	na jednosciach jest wiec wstawiam na 10 i inkrementuje
50005
	koniec.

np. 448 2
448
	dodaje 1
449
	brakuje 5
	daje na jednostki ale przez to dostane 5 na dziesiatkach
	wiec zeruje jednosci i daje 5 od razu na dziesiatkach
450

np. 9497 2
9497
	zwiekszam o 1
9498
	wstawiam z prawej
	i inkrementuje
9505
	dostalem darmowa 5
	wiec ta wstawiona kasuje
9500
	wstawiam najbardziej z prawej
9505
	koniec

PODSUMOWUJAC:
- zwiekszam o 1
- jezeli brakuje 5 to:
	wstawiam najbardziej po prawej stronie
	jezeli po wstawieniu dostane mniejsza liczbe to zwiekszam
	kolejna cyfre na lewo o 1
	jezeli w wyniku zwiekszania dostane kolejna 5 to
	zeruje ta wstawiona
*/
