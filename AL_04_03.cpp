#include <iostream>

using namespace std;

//TODO Have to find non-recursive solution since this causes stack overflow
int volume(int **structure, int N, int row, int parent, int &length)
{
    int result = 0;
    length = 1;

    for (int i = 0; i < N; ++i) {
        if (i != parent && structure[row][i] == 1) {
            int len;
            result += volume(structure, N, i, row, len);
            length += len + 1;
        }
    }

    return result + length;
}

int main()
{
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int **structure = new int*[N];
        for (int i = 0; i < N; ++i) {
            structure[i] = new int[N];
        }

        for (int i = 0; i < N - 1; ++i) {
            int left, right;
            cin >> left >> right;
            structure[left][right] = 1;
            structure[right][left] = 1;
        }

        int len;
        cout << volume(structure, N, 0, 0, len) << endl;

        for(int i = 0; i < N; ++i) {
            delete[] structure[i];
        }
        delete[] structure;
    }
}
