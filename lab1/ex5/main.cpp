#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int i=0; i<N; i++)
    {
        for (int j=i+1; j>0; j--)
        {
            cout << '*';
        }
        cout<<endl;
    }
    return 0;
}
