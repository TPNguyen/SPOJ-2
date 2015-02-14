// http://pl.spoj.com/problems/PASTAB2/

#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

bool greater_than(int a, int b)
{
    return a > b;
}

bool lower_than(int a, int b)
{
    return a < b;
}

int main()
{
    int n = 0;
    cin >> n;

    auto numbers = vector<int>(n);

    for (auto& number : numbers)
        cin >> number;

    char operation = 0;
    while (isspace(operation = cin.get()))
        ;

    int x = 0;
    cin >> x;

    bool (*condition)(int, int) = nullptr;  // powinienem to zrobic jakos
                                            // bardziej elegancko, np. funkcje
                                            // lambda czy cos...

    switch (operation) {
    case '>':
        condition = greater_than;
        break;
    case '<':
        condition = lower_than;
        break;
    }

    for (auto number : numbers)
        if (condition(number, x))
            cout << number << '\n';

    return 0;
}