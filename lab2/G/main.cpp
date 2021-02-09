#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float n, n_sqrt;
    bool prime = 1;

    cin >> n;
    n_sqrt = sqrt(n);

    int N = (int) n;
    int N_sqrt = (int) n_sqrt;

    for (int i = 2; i <= N_sqrt; i++)
    {
        if (N % i == 0) prime = 0;
    }
    cout << prime << endl;
    return 0;
}
