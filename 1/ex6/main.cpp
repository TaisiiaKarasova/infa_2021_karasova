#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int i=1; i<=N; i++)
    {
        int number_of_stars = N - (i - 1)*2;
        int first_star_position = (N - number_of_stars) / 2 + 1;
        int last_star_postion = first_star_position + number_of_stars - 1;
        for (int j=1; j<=N; j++)
        {
            if (j<first_star_position || j>last_star_postion)
                cout<<' ';
            else
                cout<<'*';
        }
        cout<<endl;
    }
    return 0;
}
