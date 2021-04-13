#include <iostream>
#include <algorithm>
using namespace std;

struct key_value
{
    int key = 0;
    int value = 0;

};

bool comp(key_value b, key_value c)
{
    if (b.key < c.key) return true;
    if (b.key == c.key) return (b.value <= c.value);
}

void sort(key_value* m, int el)
{
    int min_number = 0;
    for (int j = 0; j < el; j++)
    {
        min_number = j;
        for (int i = j; i < el; i++)
            if ((m[i].key < m[min_number].key) || (m[i].key == m[min_number].key && m[i].value < m[min_number].value))
                min_number = i;
            
        
        
        int temp;
        temp = m[j].key;
        m[j].key = m[min_number].key;
        m[min_number].key = temp;

        temp = m[j].value;
        m[j].value = m[min_number].value;
        m[min_number].value = temp;
    }
}

int main()
{
    int n;
    int value;
    cin >> n;
    key_value* A = new key_value[n];
    for (int i = 0; i < n; i++)
    {
        key_value a;
        cin >> a.key;
        a.value = 0;
        A[i] = a;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        A[i].value = value;
    }
    cout << '\n';

    sort(A, n);

    for (int i = 0; i < n; i++)
    {
        cout << A[i].key << ' ';
    }

    cout << '\n';
    for (int i = 0; i < n; i++)
    {
        cout << A[i].value << ' ';
    }
}

