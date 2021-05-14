#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int n;
    cin >> n;

    long long* res = new long long[n];

    res[1] = 3;
    res[2] = 7;

    for (int i = 3; i <= n; i++)
        res[i] = (res[i - 2] % INT_MAX + 2 * (res[i - 1] % INT_MAX)) % INT_MAX;

    cout << res[n] << '\n';
    delete[] res;
}

