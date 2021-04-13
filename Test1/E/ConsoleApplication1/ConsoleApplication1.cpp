#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

double M[10001] = { 0 };
double F[10001] = { 0 };
int main()
{
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        M[i] = 0.3 * (100 + 2 * F[i - 1]) + 10;
        F[i] = 0.7 * (100 + 2 * F[i - 1]);
    }

    cout << static_cast<int64_t>(M[n]) << '\n';

}
