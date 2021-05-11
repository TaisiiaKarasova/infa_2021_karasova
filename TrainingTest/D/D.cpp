#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

long long min_sums[2001];
int values[2001];
stack<int> steps;
int main()
{
    int n;
    cin >> n;


    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    min_sums[0] = values[0];
    min_sums[1] = values[1];

    for (int i = 2; i < n; i++)
    {
        min_sums[i] = min(min_sums[i - 1], min_sums[i - 2]) + values[i];
    }

    cout << min_sums[n - 1] << '\n';

    steps.push(n - 1);

    int i = n - 1;

    while (i >= 0)
    {
        if ((min_sums[i] - values[i]) == min_sums[i - 1])
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
