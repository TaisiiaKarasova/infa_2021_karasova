#include <iostream>
using namespace std;

int results[18];
int main()
{
    int n;
    cin >> n;
    results[0] = 1;
    results[1] = 2;
    results[2] = 4;
    for (int i = 3; i <= n; i++)
    {
        results[i] = (results[i - 1] + results[i - 2] + results[i - 3]);
    }

    cout << results[n] << '\n';
    return 0;
}