#include <iostream>
using namespace std;

bool is_prefix(string* w1, string* w2)
{
    if ((*w1).size() > (*w2).size()) return false;
    else
    {
        int length = (*w1).size();
        for (int i = 0; i < length; i++)
        {
            if ((*w1)[i] != (*w2)[i]) return false;
        }
    }

    return true;
}

string strings[256];
int results[256] = { 0 };

int main()
{
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> strings[i];
    }

    results[1] = 1;
    int max_chain = 1;
    for (int i = 2; i <= m; i++)
    {
        for (int j = 1; j < i; j++)
            if (is_prefix(&strings[j], &strings[i]) && ((results[j] + 1) > results[i]))
                results[i] = results[j] + 1;

        if (results[i] > max_chain) max_chain = results[i];
    }

    cout << max_chain << '\n';
}


