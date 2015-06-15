#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isvowel(char c) {
    string vowels = "aeiouyAEIOUY";

    return vowels.find(c) != string::npos;
}

int main()
{
    int n = 0;
    cin >> n;

    string name;
    cin >> name;

    if (name.length() <= n) {
        cout << name;
        return 0;
    }

    for (int i = name.length() - 1; i >= 0; --i) {
        char c = name[i];
        if (!isalnum(c) && c != '$') {
            name.erase(i, 1);
            if (name.length() <= n) {
                cout << name;
                return 0;
            }
        }
    }

    for (int i = name.length() - 1; i >= 0; --i) {
        char c = name[i];
        if (isdigit(c)) {
            name.erase(i, 1);
            if (name.length() <= n) {
                cout << name;
                return 0;
            }
        }
    }

    bool first = true;

    for (int i = 0; i < name.length(); ++i) {
        char c = name[i];
        if (isvowel(c)) {
            if (first) {
                first = false;
            } else {
                name.erase(i, 1);
                --i;
                if (name.length() <= n) {
                    cout << name;
                    return 0;
                }
            }
        }
    }

    int i = name.length() - 2;

    while (name.length() > n) {
        name.erase(i, 1);
        --i;
    }

    cout << name;
}
