#include <iostream>

using namespace std;

class Gauss
{
    int n;
    double** pdata; // pointer to array of matrix rows
    void swapRows(int, int);
public:
    Gauss() : n(0) {};
    Gauss(int n) : n(n) {};
    friend istream& operator>>(istream&, Gauss&);
    double operator()(int, int);
    void prinSolution();
    Gauss& operator=(Gauss&);
};

int main()
{
    int t;

    cin >> t;

    while (t--)
    {
        Gauss g;
        cin >> g;
    }

    return 0;
}

istream& operator>>(istream& is, Gauss& g)
{
    int n;
    is >> n;
    g = Gauss(n);
    return is;   
}
