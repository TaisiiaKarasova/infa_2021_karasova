#include <iostream>

using namespace std;

int main()
{
    int a, maxx, count_max;

    cin >> a;
    maxx = a;
    count_max = 0;
    while (a != 0)
    {
        if (a == maxx) count_max++;
        if (a > maxx)
        {
            maxx = a;
            count_max = 1;
        }
        cin >> a;
    }
    cout<< count_max << endl;
    return 0;
}
