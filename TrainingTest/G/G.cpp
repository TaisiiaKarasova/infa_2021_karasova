#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int min_energy[30001];
int heights[30001];
int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> heights[i];

    min_energy[1] = 0;
    min_energy[2] = abs(heights[2] - heights[1]);

    for (int i = 3; i <= n; i++)
    {
        min_energy[i] = min(min_energy[i - 2] + 3 * abs(heights[i] - heights[i - 2]), min_energy[i - 1] + abs(heights[i] - heights[i - 1]));
    }

    cout << min_energy[n] << '\n';
    return 0;
}

