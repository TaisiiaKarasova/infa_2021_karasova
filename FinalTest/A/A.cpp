#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() 
{

    int n, f, k;
    cin >> n;

    vector<pair<int, int>> waves_v;
    set<pair<int, int>> waves_s;


    for (int i = 0; i < n; i++)
    {
        cin >> f >> k;
        pair<int,int> wave;
        wave.first = f;
        wave.second = k;
        waves_s.insert(wave);
        waves_v.push_back(wave);
    }

    for (int i = 0; i < n-1; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            pair<int, int> possible_old_wave;
            possible_old_wave.first = waves_v[i].first + waves_v[j].first;
            possible_old_wave.second = waves_v[i].second + waves_v[j].second;
            if (waves_s.count(possible_old_wave))
            {
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";
}