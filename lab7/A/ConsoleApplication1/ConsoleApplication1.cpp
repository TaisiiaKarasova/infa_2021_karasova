#include <iostream>
using std::cin;
using std::cout;

int main()
{
    int a, b, c, d, x;
    cin >> a >> b >> c >> d >> x;
    if (a + x == b && c * x == d) cout << 5 << '\n';
    else if (c * x == d)  cout << 4 << '\n';
    else if (a + x == b)  cout << 4 << '\n';
    else if (x == 1024) cout << 3 << '\n';
    else cout << 2 << '\n';
    return 0;
}

