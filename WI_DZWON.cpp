#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

class Daytime
{
public:
    Daytime(int h = 0, int m = 0);
    Daytime operator+(const Daytime &dt) const;

protected:
    int hour;
    int minutes;

    friend ostream &operator<<(ostream &os, const Daytime &dt);
};

Daytime::Daytime(int h, int m)
{
    hour = h + m / 60;
    hour %= 24;
    minutes = m % 60;
}

Daytime Daytime::operator+(const Daytime &dt) const
{
    return Daytime(hour + dt.hour, minutes + dt.minutes);
}

ostream &operator<<(ostream &os, const Daytime &dt)
{
    os << setfill('0') << setw(2) << dt.hour << ":" << setw(2) << dt.minutes;
    return os;
}

int main()
{
    int hours, minutes;
    cin >> hours;
    cin.ignore(); // ignore colon
    cin >> minutes;
    Daytime bell(hours, minutes);

    cout << bell << ",";
    bell = bell + Daytime(0, 45);
    cout << bell;

    while (cin >> minutes) {
        bell = bell + Daytime(0, minutes);
        cout << "," << bell;
        bell = bell + Daytime(0, 45);
        cout << "," << bell;
    }
}
