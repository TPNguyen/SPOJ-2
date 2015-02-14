#include <iostream>
#include <vector>

using namespace std;

class Znajomosci
{
public:
    bool czy_zna(int kto, int kogo);
    Znajomosci(int osob);
    ~Znajomosci();
    bool **zna;
    int ile_osob;
};

class Druzyna
{
public:
    vector<int> osoby;
    bool czy_moze_dolaczyc(int kto, Znajomosci &z);
    bool czy_ktos_go_zna(int kogo, Znajomosci &z);
    void dodaj(int kogo);
};

int main()
{
    Druzyna d[3];
    int n, i;
    
    cin >> n;

    Znajomosci z(n);

    for (i = 0; i < n; ++i)
    {
        if (d[0].czy_moze_dolaczyc(i, z) && !d[1].czy_ktos_go_zna(i, z) && !d[2].czy_ktos_go_zna(i, z))
            d[0].dodaj(i);
        else if (d[1].czy_moze_dolaczyc(i, z) && !d[0].czy_ktos_go_zna(i, z) && !d[2].czy_ktos_go_zna(i, z))
            d[1].dodaj(i);
        else if (d[2].czy_moze_dolaczyc(i, z) && !d[0].czy_ktos_go_zna(i, z) && !d[1].czy_ktos_go_zna(i, z))
            d[2].dodaj(i);
        else break;
    }

    if (i == n)
        cout << "TAK" << endl;
    else
        cout << "NIE" << endl;

    return 0;
}

Znajomosci::Znajomosci(int osob) : ile_osob(osob)
{
    zna = new bool *[ile_osob];
    for (int i = 0; i < ile_osob; ++i)
        zna[i] = new bool[ile_osob];

    for (int i = 0; i < ile_osob; ++i)
        for (int j = 0; j < ile_osob; ++j)
            cin >> zna[i][j];
}

Znajomosci::~Znajomosci()
{
    for (int i = 0; i < ile_osob; ++i)
        delete[] zna[i];
    delete[] zna;
}

bool Znajomosci::czy_zna(int kto, int kogo)
{
    return zna[kto][kogo];
}

bool Druzyna::czy_moze_dolaczyc(int kto, Znajomosci &z)
{
    if (osoby.size() == 0)
        return true;

    for (vector<int>::iterator it = osoby.begin(); it != osoby.end(); ++it)
    {
        if (!z.czy_zna(*it, kto))
            return false; //jezeli jest w zespole ktos kto nie zna nowego
    }

    return true;
}

void Druzyna::dodaj(int kogo)
{
    osoby.push_back(kogo);
}

bool Druzyna::czy_ktos_go_zna(int kogo, Znajomosci &z)
{
    for (vector<int>::iterator it = osoby.begin(); it != osoby.end(); ++it)
    {
        if (z.czy_zna(*it, kogo))
            return true;
    }
    
    return false;
}
