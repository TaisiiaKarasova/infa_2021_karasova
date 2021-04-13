#include <iostream>
using std::cin;
using std::cout;


int main()
{
    long long n;
    long long a;
    cin >> n;
    cin >> a;
    long long value;
    long long number = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> value;
        if (value == a) number = i;
    }

    cout << number << '\n';
}

