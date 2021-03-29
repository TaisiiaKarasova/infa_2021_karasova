#include <iostream>
#include <vector>
using std::cin;
using std::cout;

bool unpleasant_4(int n)
{
    if (n % 4 != 0) return false;
    if (n / 1000 == 4 || n / 1000 == 5) return false;
    return true;
}

bool unpleasant_7(int n)
{
    if (n % 7 != 0) return false;
    if (n / 1000 == 7 || n / 1000 == 1) return false;
    return true;
}

bool unpleasant_9(int n)
{
    if (n % 9 != 0) return false;
    if (n / 1000 == 9 || n / 1000 == 8) return false;
    return true;
}


int main()
{
    int n, a;

    cin >> n;
    std::vector<int> unpleasant;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        if (unpleasant_4(a) || unpleasant_7(a) || unpleasant_9(a))
        {
            unpleasant.push_back(a);
        }
            
    }

    if (unpleasant.size() != 0) for (int n : unpleasant) cout << n << '\n';
    else cout << 0 << '\n';
    return 0;
}
