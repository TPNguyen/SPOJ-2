#include <iostream>

using namespace std;

void shift_right(int *left, int *right);
void shift_left(int *left, int *right);
int abs(int a);

int main()
{
    int t, k, i, j;
    int value;
    int *tab;
    struct best_shift
    {
        int shift;
        int value;
    } best_shift;

    cin >> t;

    while (t--)
    {
        cin >> k;

        tab = new int[k];

        for (i = 0; i < k; ++i)
            cin >> tab[i];

        value = 0;
        for (j = 0; j < k; ++j)
            if (j + 1 == tab[j])
                ++value;

        best_shift.value = value;
        best_shift.shift = 0;

        for (i = 0; i < k; ++i)
        {
            shift_left(tab, tab + k - 1);

            value = 0;
            for (j = 0; j < k; ++j)
                if (j + 1 == tab[j])
                    ++value;

            if (value > best_shift.value)
            {
                best_shift.value = value;
                best_shift.shift = i + 1;
            }
        }

        for (i = 0; i < best_shift.shift; ++i)
            shift_left(tab, tab + k - 1);

        for (i = 0; i < k; ++i)
            cout << tab[i] << " ";

        cout << endl;

        delete[] tab;
    }

    return 0;
}

void shift_right(int *left, int *right)
{
    int temp = *right;

    while (right != left)
    {
        *right = *(right - 1);
        --right;
    }

    *left = temp;
}

void shift_left(int *left, int *right)
{
    int temp = *left;

    while (right != left)
    {
        *left = *(left + 1);
        ++left;
    }

    *right = temp;
}

int abs(int a)
{
    return a > 0 ? a : -a;
}
