#include <iostream>
#include <vector>

using namespace std;

class Base_11
{
private:
    int value;
public:
    Base_11(int value = 0) : value(value) {}
    friend ostream& operator<<(ostream&, Base_11);
};

ostream& operator<<(ostream& os, Base_11 output)
{
    auto flag = os.setf(ios::hex, ios::basefield);
    
    auto output_vector = vector<int>();
    int n = output.value;

    if (n == 0)
        os << 0;
    else
        while (n > 0) {
            output_vector.push_back(n % 11);
            n /= 11;
        }

    for (auto it = output_vector.rbegin(); it != output_vector.rend(); ++it) {
        os << *it;
    }

    os.flags(flag);
    return os;
}

int main()
{
    int t = 0;
    cin >> t;

    cout << uppercase;

    while (t--) {
        int n = 0;
        cin >> n;
        cout << hex << n << " " << Base_11(n) << '\n';
    }

    return 0;
}
