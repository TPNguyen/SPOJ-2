// wstyd taki kod pokazywac...
#include <iostream>
#include <algorithm>

using namespace std;

bool **zna;
int *osoby;
int ile_osob;

int pierwsza_wolna_osoba()
{
    int j = 0;
    while (osoby[j] != -1 && j < ile_osob) //wez pierwsza wolna osobe...
        ++j;
    if (j < ile_osob)
        return j;
    return -1;
}

bool dodaj_wszystkich_znajomych(int czyich)
{
    for (int i = 0; i < ile_osob; ++i)
        if (i != czyich && zna[czyich][i])
            if (osoby[i] == -1)
                osoby[i] = osoby[czyich];
            else
                return false;
    return true;
}

int main()
{
    int i;
    int osoba;

    cin >> ile_osob;

    zna = new bool *[ile_osob];
    for (i = 0; i < ile_osob; ++i)
        zna[i] = new bool[ile_osob];

    for (i = 0; i < ile_osob; ++i)
        for (int j = 0; j < ile_osob; ++j)
            cin >> zna[i][j];
        

    osoby = new int[ile_osob];

    for (int i = 0; i < ile_osob; ++i)
        osoby[i] = -1;

    for (i = 0; i < 3; ++i) //dla kazdego z teamow...
    {
        if ((osoba = pierwsza_wolna_osoba()) < 0)
            break;

        osoby[osoba] = i;

        if (!dodaj_wszystkich_znajomych(osoba))
            break;
    }

    bool sukces = true;

    int druzyna[3];
    for (i = 0; i < 3; ++i)
        druzyna[i] = 0;
    for (i = 0; i < ile_osob; ++i)
    {
        if (osoby[i] >= 0)
            ++druzyna[osoby[i]];
        else
        {
            sukces = false;
            break;
        }
    }

    for (i = 0; i < 3; ++i)
        if (druzyna[i] == 0)
            sukces = false;

    if (sukces)
    {
        cout << "TAK ";
        sort(&druzyna[0], &druzyna[3]);
        for (i = 0; i < 3; ++i)
            cout << druzyna[i] << " ";
        cout << endl;
    }
    else
        cout << "NIE" << endl;

    delete[] osoby;

    for (i = 0; i < ile_osob; ++i)
        delete zna[i];
    delete zna;

    return 0;
}
