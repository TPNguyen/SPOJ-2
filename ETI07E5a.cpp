//trzeba bylo dac wszedzie long long int zeby bylo 100pkt
//mnie sie z takim typem nie kompiluje
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long int absolute(long int a)
{
    return a >= 0 ? a : -a;
}

int main()
{
    long int n, x, y;
    long int x_res, total = 0;
    vector<long int> x_vec;

    cin >> n;

    while (n--)
    {
        cin >> x >> y;
        x_vec.push_back(x);
        total += absolute(y);
    }

    sort(x_vec.begin(), x_vec.end());

    x_res = x_vec[(x_vec.size() - 1) / 2];

    for (vector<long int>::iterator it = x_vec.begin(); it != x_vec.end(); ++it)
        total += absolute(*it - x_res);

    cout << x_res << " " << total << endl;

    return 0;
}
