#include <iostream>

using namespace std;

int main()
{
    int a;
    cin>> a;

   if (( a & (a - 1) ) == 0) cout<<"YES"<<endl;
   else cout<<"NO"<<endl;
    return 0;
}
