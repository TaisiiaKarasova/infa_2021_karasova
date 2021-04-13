#include <iostream>
#include <vector>
using std::cin;
using std::cout;

int main()
{
    std::vector<long long> t;
    t.push_back(0);
    t.push_back(0);
    t.push_back(1);
    
    long long a;
    cin >> a;
    long long i = 2;
    long long last_t = 1;

    if (a < 0) cout << 0 << '\n';
    else if (a == 0) cout << 2 << '\n';
    else
    {
        while (last_t <= a)
        {
            last_t = t[i] + t[i - 1] + t[i - 2];
            t.push_back(last_t);
            i++;
        }

        cout << i << '\n';
    }
}

