#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int q;

    cin >> s >> q;

    while (q--)
    {
        int n;

        cin >> n;
        
        if (n > 0)
        {
            for (int i = 0; i < s.size(); ++i)
            {
                cout << s[i];
                if (i != s.size() - 1)
                    for (int j = 0; j < n - 1; ++j)
                        cout << " ";
            }
        }
        else if (n < 0)
        {
            for (int i = 0; i < s.size(); ++i)
            {
                cout << s[s.size() - i - 1];
                if (i != s.size() - 1)
                    for (int j = 0; j < - n - 1; ++j)
                        cout << " ";
            }
        }
        else
            cout << s[s.size() - 1];

        if (q)
            cout << endl;
    }

    return 0;
}
