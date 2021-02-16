#include <iostream>

using namespace std;

int main()
{
    int N;
    int greater_average_sum = 0;
    double average = 0;
    cin >> N;
    int* a = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> *(a + i);
        average += *(a + i);
    }
    average = average / N;

    for (int i = 0; i < N; i++)
    {
        if (*(a + i) > average) greater_average_sum += *(a + i);
    }

    delete[] a;
    cout << greater_average_sum << endl;
    return 0;
}

