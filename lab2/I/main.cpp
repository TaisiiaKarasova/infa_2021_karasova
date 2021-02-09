#include <iostream>
#include <vector>

using namespace std;

int coincidances (string s)
{
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    if (s[1]==s[2])
    {
        count1++;
        count2++;
    }
    if (s[1]==s[3])
    {
        count1++;
        count3++;
    }
    if (s[2]==s[3])
    {
        count2++;
        count3++;
    }
    return max(count1, max(count2, count3));
}
string numbers[1000000];
int speeds[1000000];
int main()
{
    string nomer;
    int speed, salary = 0;
    int c = 0;

    while (cin>>speed)
    {
        speeds[c] = speed;
        cin >> numbers[c];
        if (numbers[c]=="A999AA") break;
        c++;
    }

    c = 0;

    while (numbers[c] != "A999AA")
    {
        if (speeds[c] > 60)
        {
            if (coincidances(numbers[c]) == 2) salary+=1000;
            if (coincidances(numbers[c]) == 1) salary+=500;
            if (coincidances(numbers[c]) == 0) salary+=100;
        }
        c++;
    }
    cout << salary << endl;
    return 0;
}
