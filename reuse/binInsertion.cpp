#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int>::iterator binInsertion(
        vector<int>::iterator first ,
        vector<int>::iterator last ,
        int x )
{
    if (first >= last)
        return first;
    
    vector<int>::iterator middle = first + (last - first) / 2;

    if (*middle == x)
    {
        while (*(middle - 1) == x) // !!
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
    vector<int> A;
    int t[] = {8, 20, 8, 8, 16, 101, 89, 8, 8, 8, 8};
    vector<int>::iterator it;

    for (int i = 0; i < 11; ++i)
        A.push_back(t[i]);

    for (it = A.begin(); it != A.end(); ++it)
        cout << *it << " ";
    cout << endl;
    
    sort(A.begin(), A.end());

    for (it = A.begin(); it != A.end(); ++it)
        cout << "A[" << it - A.begin() << "] = " << *it << endl;
    cout << endl;
    
    int szukana = 8;
    cout << "szukana " << szukana << " ma indeks ";
    cout << binInsertion(A.begin(), A.end(), szukana) - A.begin() << endl;

    return 0;
}
