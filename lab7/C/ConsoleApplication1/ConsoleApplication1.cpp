#include <iostream>
#include <vector>
#include <iomanip>

using std::cin;
using std::cout;

int main()
{
    std::vector<int> values;
    double value;
    double sum = 0;
    double sum_squares = 0;

    cin >> value;
    while (value != 0)
    {
        values.push_back(value);
        sum += value;
        sum_squares += value * value;
        cin >> value;
    }

    double M = sum / values.size();
    double D = sum_squares / values.size() - M * M;
    std::cout << std::fixed << std::setprecision(3) << M << ' ' << D << '\n';
    return 0;
}
