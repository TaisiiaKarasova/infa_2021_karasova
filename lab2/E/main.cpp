#include <iostream>

using namespace std;

int main()
{
    int a, max_even;

    cin >> a;
    max_even = 0;
    while (a != 0)
    {
        if ((a % 2 == 0) && (a > max_even)) max_even = a;
        cin >> a;
    }
    cout<< max_even << endl;
    return 0;
}
