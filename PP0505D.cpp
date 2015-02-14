/*     Laboratorium Praktyki Programowania   */
#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

#define T_SIZE 50

void gray(int, int *, int =0, char =1);

int main()
{
    int t,n,tab[T_SIZE];
    cin >> t; /* wczytaj liczbę testów */
    
    while(t)
    {
        cin >> n;
        assert(n<=T_SIZE);
        gray(n, tab);
        cout << endl;
        t--;
    }
    
    return 0;
}  

/* ........................  Tu napisz potrzebne funkcje */ 

void gray(int n, int *tab, int k, char direction)
{
    if (n == k)
    {
        for (int i = 0; i < n; ++i)
            cout << tab[i];
        cout << endl;
    }
    else
    {
        if (direction == 1)
        {
            tab[k] = 0;
            gray(n, tab, k+1, 1);
            tab[k] = 1;
            gray(n, tab, k+1, 0);
        }
        else
        {
            tab[k] = 1;
            gray(n, tab, k+1, 1);
            tab[k] = 0;
            gray(n, tab, k+1, 0);
        }
    }
}
