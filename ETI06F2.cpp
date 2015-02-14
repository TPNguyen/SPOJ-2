#include <iostream>

using namespace std;

int main()
{
    int k, t, pd, s, r;
    char *res;

    t = pd = 2;
    s = 1;

    cin >> k;

    while (k > t)
    {
        pd *= 2;
        t += pd; // do t sa dodawane kolejne potegi 2
        ++s; // liczba znakow w wyniku
    }

    r = k - (t - pd) - 1;

    res = new char[s + 1];

    res[s] = '\0';
    while (s--)
    {
        res[s] = '5' + r % 2; // analogia do zamiany dziesietnych na binarne
        r /= 2;
    }

    cout << res << endl;

    delete[] res;

    return 0;
}
