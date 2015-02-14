// http://pl.spoj.com/problems/MWPZ06H/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int D = 0;  // liczba zestawow danych
    cin >> D;

    auto results = vector<int>(200);
    auto it = results.begin();

    while (D--) {
        int N = 0;  // liczba uczestnikow konkursu
        cin >> N;
        // wczytanie wynkow konkursu
        for (int i = 0; i < N; ++i)
            cin >> results[i];

        // znalezienie najwyzszego wyniku
        it = max_element(results.begin(), results.begin() + N);

        // umieszczenie najwyzszego wyniku na poczatku listy
        iter_swap(results.begin(), it);

        int winners = 1;
        while (winners < N &&
               (it = find(results.begin() + winners, results.begin() + N,
                          results[0])) != results.begin() + N) {
            iter_swap(results.begin() + winners, it);
            ++winners;
        }

        sort(results.begin() + winners, results.begin() + N);

        for (it = results.begin(); it != results.begin() + N; ++it) {
            cout << *it << ' ';
        }
        cout << '\n';
    }

    return 0;
}