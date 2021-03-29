#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
using std::cin;
using std::cout;

bool comp(int b, int c)
{
    if (((b & 1) == 0) && ((c & 1) == 0)) return (b < c);
    if (((b & 1) != 0) && ((c & 1) != 0)) return (b < c);
    if (((b & 1) != 0) && ((c & 1) == 0)) return false;
    if (((b & 1) == 0) && ((c & 1) != 0)) return true;

}

int a[10001];
int main()
{
    int x;
    int number_of_values = 0;
    while (std::cin >> x)
    {
        a[number_of_values] = x;
        number_of_values++;
    }
    sort(a, a + number_of_values, comp);
    for (int i = 0; i < number_of_values; i++)
    {
        cout << a[i] << ' ';
    }
    cout << '\n';
    return 0;
}

