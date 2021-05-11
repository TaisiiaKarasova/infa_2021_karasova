#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long long options[10001];
long long values[10001];
int main()
{
    int n, options_from_far_places;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> values[i];

    options[1] = options[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        options_from_far_places = 0;
        for (int j = 1; j < i - 1; j++)
            if (values[j] == (i - j)) 
                options_from_far_places = (options_from_far_places + options[j]) % 937;

        options[i] = (options_from_far_places + options[i - 1]) % 937;
    }

    cout << options[n] % 937 << '\n';
    return 0;
}
