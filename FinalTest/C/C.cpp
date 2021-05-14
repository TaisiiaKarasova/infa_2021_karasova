#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct person
{
    string name;
    long long number;
    long long sum;
};

bool comp(person A, person B)
{
    if (A.sum < B.sum) return true;
    else return false;
}

int main()
{
    int n;
    cin >> n;
    int borg = 0;
    person* people = new person[n];

    for (int i = 0; i < n; i++)
    {
        cin >> people[i].name >> people[i].number >> people[i].sum;
        if (people[i].sum < 0) borg++;
    }

    sort(people, people + n, comp);

    if (borg <= 100)
        for (int i = 0; i < borg; i++) cout << people[i].name << ' ' << people[i].number << ' ' << people[i].sum << '\n';
    else
        for (int i = 0; i < 100; i++) cout << people[i].name << ' ' << people[i].number << ' ' << people[i].sum << '\n';

    delete[] people;
}
