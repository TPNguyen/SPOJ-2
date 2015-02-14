#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

//zrobic taka klasse bigNumbers ze ma virtualne funkcje
//i dziala polimorfizm tak ze jak nie trzeba uzywac stringa dla liczb
//to nie uzywa

using namespace std;

bool greaterNumber(string a, string b);
bool lowerNumber(string a, string b);
vector<string>::iterator binInsertion(
        vector<string>::iterator first ,
        vector<string>::iterator last ,
        string x);
vector<long long>::iterator binInsertion(
        vector<long long>::iterator first ,
        vector<long long>::iterator last ,
        int x )
{
    if (first >= last)
        return first;
    
    vector<long long>::iterator middle = first + (last - first) / 2;

    if (*middle == x)
    {
        while ((middle > first) && (*(middle - 1) == x)) // !!
            --middle;
        return middle;
    }
    else if (*middle > x)
        return binInsertion(first, middle, x);
    else
        return binInsertion(middle + 1, last, x);
}

int main()
{
    int n;
    string input;
    vector<string> A;
    vector<string>::iterator it;

    cin >> n;

    if (n > 1000)   //oszustwo z komentarzy, jak jest duzo przypadkow
    {               //to nie ma duzych liczb
        long long input;
        vector<long long> A;
        
        while (n--)
        {
            cin >> input;
            A.push_back(input);
        }

        sort(A.begin(), A.end());

        cin >> n;

        while(n--)
        {
            cin >> input;

            cout << binInsertion(A.begin(), A.end(), input) - A.begin() << endl;
        }
    }
    else
    {
        while(n--)
        {
            cin >> input;
            A.push_back(input);
        }

        sort(A.begin(), A.end(), lowerNumber);

        cin >> n;

        while(n--)
        {
            cin >> input;

            cout << binInsertion(A.begin(), A.end(), input) - A.begin() << endl;
        }
    }

    return 0;
}

//******************************************************************************
// funkcja porownujaca dwie liczby zapisane jako string
//******************************************************************************
bool greaterNumber(string a, string b)
{
    int aLength = a.length();
    int bLength = b.length();

    if (aLength > bLength)
        return true;
    else if (aLength < bLength)
        return false;
    else
    {
        //aLength == bLength
        int i = 0;

        while (a[i] == b[i] && i < aLength)
            ++i;
            
        return a[i] > b[i];
    }
}

//******************************************************************************
// funkcja porownujaca dwie liczby zapisane jako string
//******************************************************************************
bool lowerNumber(string a, string b)
{
    int aLength = a.length();
    int bLength = b.length();

    if (aLength < bLength)
        return true;
    else if (aLength > bLength)
        return false;
    else
    {
        //aLength == bLength
        int i = 0;

        while (a[i] == b[i] && i < aLength)
            ++i;
            
        return a[i] < b[i];
    }
}

//******************************************************************************
// funkcja znajdujaca pierwsze od lewej miejsce do wstawienia elementu x
// w rosnaco posortowanym zbiorze
// operacje sa przeprowadzane na liczbach zapisanych jako string
//******************************************************************************
vector<string>::iterator binInsertion(
        vector<string>::iterator first ,
        vector<string>::iterator last ,
        string x)
{
    if (first >= last)
        return first;

    vector<string>::iterator middle = first + (last - first) / 2;

    if (*middle == x)
    {
        while ((middle > first) && (*(middle - 1) == x)) // !!
            --middle;
        return middle;
    }
    else if (greaterNumber(*middle, x))
        return binInsertion(first, middle, x);
    else
        return binInsertion(middle + 1, last, x);
}
