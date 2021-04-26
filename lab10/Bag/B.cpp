#include <iostream>
#include <algorithm>
using namespace std;

int costs[101];
int masses[101];
int table_calc[1001][101];

int main()
{
    int w;
    int n;


    cin >> w >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> costs[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> masses[i];
    }

    for (int i = 0; i <= n; i++)
    {
        table_calc[0][i] = 0;
    }

    for (int i = 0; i <= w; i++)
    {
        table_calc[i][0] = 0;
    }

    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= w; i++)
        {
            if (i >= masses[j])
            {
                table_calc[i][j] = max(table_calc[i - masses[j]][j - 1] + costs[j], table_calc[i][j - 1]);
            }
            else
            {
                table_calc[i][j] = table_calc[i][j - 1];
            }
        }
    }

    cout << table_calc[w][n] << '\n';


    return 0;
}

