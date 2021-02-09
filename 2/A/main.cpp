#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b;
    if (a < b)
    {
        c = b;
        b = a;
        a = c;
    }

    while (b > 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    cout << a;

    return 0;
}
