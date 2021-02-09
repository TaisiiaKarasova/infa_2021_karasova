#include <iostream>

using namespace std;

int main()
{
    int a, c=0;

    cin>>a;

    while (a != 0)
    {
        if (a % 2 == 0) c++;
        cin>> a;
    }
    cout<<c;
    return 0;
}
