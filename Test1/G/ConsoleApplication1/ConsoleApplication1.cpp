#include <iostream>
using std::cin;
using std::cout;

int A[1000001];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        cout << A[i] << ' ';
    }

    cout << '\n';
}

