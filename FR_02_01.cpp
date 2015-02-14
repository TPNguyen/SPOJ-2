#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double x[4], y[4], r;
    double t[7];

    for (int i = 1; i <= 3; ++i)
        cin >> x[i] >> y[i];

    t[0] = 2 * (x[2] - x[1]);
    t[1] = 2 * (y[2] - y[1]);
    t[2] = x[1] * x[1] + y[1] * y[1];
    t[3] = x[2] * x[2] + y[2] * y[2] - t[2];
    t[4] = 2 * (x[3] - x[1]);
    t[5] = 2 * (y[3] - y[1]);
    t[6] = x[3] * x[3] + y[3] * y[3] - t[2];

    x[0] = (t[6] * t[1] - t[5] * t[3]) / (t[4] * t[1] - t[0] * t[5]);
    y[0] = (t[6] * t[0] - t[4] * t[3]) / (t[5] * t[0] - t[4] * t[1]);

    r = sqrt( (x[1] - x[0]) * (x[1] - x[0]) + (y[1] - y[0]) * (y[1] - y[0]) );

    cout << fixed << setprecision(2) << r;

    return 0;
}
