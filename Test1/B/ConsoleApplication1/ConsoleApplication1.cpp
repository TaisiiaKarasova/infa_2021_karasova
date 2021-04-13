#include <iostream>
#include <string>
using std::cin;
using std::cout;

int main()
{
    int i = 0;
    std::string s;

    while (cin >> s)
    {
        i++;
    }


    std::cout << i << '\n';
}
