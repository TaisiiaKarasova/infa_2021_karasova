#include <iostream>
using namespace std;

int results[18];
int main()
{
    int k, n;
    cin >> n >> k;
    results[0] = 1;
    results[1] = k - 1;
    for (int i = 2; i <= n; i++)
    {
        results[i] = (results[i - 1] + results[i - 2]) * (k - 1);
    }

    cout << results[n] << '\n';
    return 0;
}

