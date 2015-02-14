#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
    int Z, d, n;
    const double pi05 = acos(-1.0) / 2;
    double coIle;

    scanf("%d", &Z);

    while (Z--)
    {
        scanf("%d %d", &d, &n);

        n = n % 2 ? n : n / 2;
        coIle = pi05 * d / n;

        //cout << setprecision(3) << fixed << coIle;
        printf("%.3f %d\n", coIle, n);
    }

    return 0;
}
