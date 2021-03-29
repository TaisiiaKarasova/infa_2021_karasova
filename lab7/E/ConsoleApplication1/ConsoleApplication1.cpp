#include <iostream>

using std::cin;
using std::cout;
int a[1001][1001];
int main()
{
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> a[j][n - 1 - i];
        }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }

    return 0;

}

