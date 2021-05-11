#include <iostream>
using namespace std;

int results[21];
int main()
{
    int n;
    cin >> n;
    results[1] = 3;
    results[2] = 8;
    for (int i = 3; i <= n; i++)
    {
        results[i] = (2 * results[i - 1] + 2 * results[i - 2]);
    }

    cout << results[n] << '\n';
    return 0;
}
