#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, j = 2;
    cin >> n;
    while (n >= 0)
    {
        if (n % j == 0)
        {
            cout<<j<<endl;
            n = n / j;
        }
        else j++;
    }
    return 0;
}
