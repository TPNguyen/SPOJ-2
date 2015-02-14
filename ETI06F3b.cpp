//------------------------------------------------------------------------------
// Najpierw wybrac trzech ktorzy sie nie znaja miedzy soba
//------------------------------------------------------------------------------
#include <iostream>

using namespace std;

class Druzyny
{
public:
    Druzyny(int osob, int druzyn);
    ~Druzyny();
    class Druzyna
    {
    public:
        Druzyna() : ilu_w_druzynie(0), max_w_druzynie(0), zawodnik(NULL){};
        Druzyna(int max) : ilu_w_druzynie(0), max_w_druzynie(max)
        {
            zawodnik = new int[max_w_druzynie];
        }
        ~Druzyna()
        {
            if (zawodnik != NULL)
                delete[] zawodnik;
        }
        bool znaja(int kogo);
        void dodaj(int kogo);
    private:
        int ilu_w_druzynie;
        int max_w_druzynie;
        int *zawodnik;
    } *druzyna;
    const int ile_osob;
    const int ile_druzyn;
private:
    bool **znajomosci;
};

Druzyny::Druzyny(int osob, int druzyn) : ile_osob(osob), ile_druzyn(druzyn)
{
    znajomosci = new bool *[ile_osob];
    for (int i = 0; i < ile_osob; ++i)
        znajomosci[i] = new bool[ile_osob];

    for (int i = 0; i < ile_osob; ++i)
        for (int j = 0; j < ile_osob; ++j)
            cin >> znajomosci[i][j];

    druzyna = new Druzyna[ile_druzyn];

    for (int i = 0; i < ile_druzyn; ++i)
        druzyna[i] = Druzyna(ile_osob);
}

Druzyny::~Druzyny()
{
    for (int i = 0; i < ile_druzyn; ++i)
        delete[] znajomosci[i];
    delete[] znajomosci;

    delete[] druzyna;
}

bool Druzyny::Druzyna::znaja(int kogo)
{
    return true;
}

int main()
{
    int n;

    cin >> n;

    Druzyny d(n, 3);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 3; ++j)
            cout << d.druzyna[j].znaja(i) << endl;

    return 0;
}
