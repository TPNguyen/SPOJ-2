#include <iostream>

using namespace std;

int main()
{
    int D, X, Y, Z;
    double result;

    cin >> D;

    while (D--)
    {
        cin >> X >> Y >> Z;
        
        result = (X + Y - Z * Y) * -12 / (Z - 1.0);

        cout << int(result + 0.5) << endl;
    }

    return 0;
}
