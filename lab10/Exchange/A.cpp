#include <iostream>
#include <algorithm>
using namespace std;

int monets[101];
int table_calc[1001][101];

int main()
{
    int s;
    int n;
    cin >> s >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> monets[i];
    }
    for (int i = 0; i <= n; i++)
    {
        table_calc[0][i] = 0;
    }
    for (int i = 1; i <= s; i++)
    {
        table_calc[i][0] = s + 1;
    }


    sort(monets, monets + n);

    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= s; i++)
        {
            if (monets[j] > i)
                table_calc[i][j] = table_calc[i][j - 1];
            else
                table_calc[i][j] = min(table_calc[i][j - 1], table_calc[i - monets[j]][j] + 1);
        }
    }

   
    cout << table_calc[s][n] << '\n';



    return 0;
}


