#include <iostream>

using namespace std;

string two_digit_to_vavilon (int n)
{
    string res = "";
    for (int j = 1; j <= (n / 10); j++)
    {
        res += "<";
    }
    for (int j = 1; j <= (n % 10); j++)
    {
        res += "v";
    }
    return res;
}

int remainders[10000000] = {0};
string remainders_in_vavilon [10000000];
int main()
{
    int n, quotient, c;
    c = 0;
    cin >> n;
    quotient = n / 60;
    while (quotient > 0)
    {
        quotient = n / 60;
        remainders[c] = n % 60;
        n = n / 60;
        c++;
    }
    for (int i = c - 1; i > 0; i--)
    {
        cout<<two_digit_to_vavilon(remainders[i])<<'.';
    }
    cout<<two_digit_to_vavilon(remainders[0])<<endl;
    cout<<endl;
    return 0;
}
