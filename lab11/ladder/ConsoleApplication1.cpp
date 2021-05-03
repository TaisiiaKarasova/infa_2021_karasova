#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

long long max_sums[2001];
int values[2001];
stack<int> steps;
int main()
{
    int n;
    cin >> n;
    values[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> values[i];
    }

    max_sums[0] = 0;
    max_sums[1] = values[1];

    for (int i = 2; i <= n; i++)
    {
        max_sums[i] = max(max_sums[i - 1], max_sums[i - 2]) + values[i];
    }
    
    cout << max_sums[n] << '\n';

    steps.push(n);

    int i = n;

    while (i != 0)
    {
        if ((max_sums[i] - values[i]) == max_sums[i - 1] && values[i - 1] != 0)
        {
            steps.push(i - 1);
            i--;
        }
        else
        {
            steps.push(i - 2);
            i -= 2;
        }
        
    }

    steps.pop();
    int number_of_steps = steps.size();
    for (int i = 1; i <= number_of_steps; i++)
    {
        cout << steps.top() << ' ';
        steps.pop();
    }
    cout << '\n';
    
}


