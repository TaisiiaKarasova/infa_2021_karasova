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
    if (A.sum > B.sum) return true;
    else if (A.sum < B.sum) return false;
    else if (A.name < B.name) return true;
    else if (A.name > B.name) return false;
    else if (A.number < B.number) return true;
    else return false;

}

int main()
{
    int n;
    cin >> n;
    person* people = new person[n];


    for (int i = 0; i < n; i++)
    {
        cin >> people[i].name >> people[i].number >> people[i].sum;
    }

    sort(people, people + n, comp);

    if (n <= 10)
        for (int i = 0; i < n; i++) cout << people[i].name << ' ' << people[i].number << ' ' << people[i].sum << '\n';
    else
        for (int i = 0; i < 10; i++) cout << people[i].name << ' ' << people[i].number << ' ' << people[i].sum << '\n';
    
}


