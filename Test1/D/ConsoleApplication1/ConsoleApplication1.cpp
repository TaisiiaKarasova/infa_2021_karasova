#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


long long max_number(std::string s)
{
    long long n = s.length();
    long long i = 0;
    long long maxx = LLONG_MIN;
    long long current_number = 0;

    while (i < n)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            current_number = 0;
            while (s[i] >= '0' && s[i] <= '9' && i < n)
            {
                current_number = current_number * 10 + (s[i] - '0');
                i++;
            }
            if (current_number > maxx) maxx = current_number;
        }
        i++;
    }

    return maxx;
}

int main()
{
    std::string s;
    getline(cin, s);

    cout << max_number(s) << '\n';

}

