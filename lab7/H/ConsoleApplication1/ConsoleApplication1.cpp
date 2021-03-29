#include <iostream>

using std::cin;
using std::cout;

int pairs[1000001];
int slippers[1000001];

int min_and_not_zero(int m[], int size)
{
    int minn;
    minn = 2147483646;
    bool all_zeros = true;
    for (int y = 0; y < size; y++)
    {
        if (m[y] < minn && m[y]!=0)
        {
            minn = m[y];
            all_zeros = false;
        }

    }
    if (all_zeros) return 0;
    return minn;
}

int main()
{
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        slippers[i] = a;
        if (a >= 0)
            for (int j = i - 1; j >= 0; j--)
                if ((slippers[j] == -slippers[i] && (i - j) < pairs[j]) || (slippers[j] == -slippers[i] && pairs[j] == 0))
                {
                    pairs[j] = pairs[i] = i - j;
                    
                }
    }

    cout << min_and_not_zero(pairs, n) << '\n';
    return 0;
}

