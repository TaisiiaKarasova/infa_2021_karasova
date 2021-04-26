#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int pins_coords[101];
int threads_min[101];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> pins_coords[i];
	}

	sort(pins_coords, pins_coords + n);

	threads_min[0] = 0;
	threads_min[1] = pins_coords[1] - pins_coords[0];
	threads_min[2] = pins_coords[2] - pins_coords[0];

	for (int i = 3; i < n; i++)
	{
		threads_min[i] = min(threads_min[i - 1], threads_min[i - 2]) + pins_coords[i] - pins_coords[i - 1];
	}

	cout << threads_min[n - 1];

	
	return 0;
}