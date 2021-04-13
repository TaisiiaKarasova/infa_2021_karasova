#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void change_regist(std::string* st)
{
    int n = (*st).length();

    int i = 0;
    int not_empty = 0;
    while (i < n)
    {
        if ((*st)[i] != ' ')
        {
            if (not_empty % 2 == 0) (*st)[i] = std::toupper((*st)[i]);
            else (*st)[i] = std::tolower((*st)[i]);

            not_empty++;
        }
        i++;
    }
}
int main()
{
    int n_elements = 0;
    std::string s;
    std::vector<std::string> strings;

    getline(cin, s);

    change_regist(&s);

    cout << s;
}
