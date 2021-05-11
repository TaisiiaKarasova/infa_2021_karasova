#include <iostream>
using namespace std;

int numbers[101];
int results[101] = { 0 };

int main()
{
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> numbers[i];
        results[i] = 1;
    }

    
    int max_chain = 1;
    for (int i = 2; i <= m; i++)
    {
        for (int j = 1; j < i; j++)
            if ((numbers[j] < numbers[i]) && ((results[j] + 1) > results[i]))
                results[i] = results[j] + 1;

        if (results[i] > max_chain) max_chain = results[i];
    }

    cout << max_chain << '\n';
}
