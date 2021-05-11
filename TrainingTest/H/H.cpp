#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int from_letter_to_number(char c)
{
	if (c == 'a') return 1;
	if (c == 'b') return 2;
	if (c == 'c') return 3;
	if (c == 'd') return 4;
	if (c == 'e') return 5;
	if (c == 'f') return 6;
	if (c == 'g') return 7;
	if (c == 'h') return 8;
}
bool positions[65][65] = { 0 };
int options[65][65] = { 0 };
int main()
{
	int n, row, column;
	string s;
	cin >> n;
	int size = 8;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		positions[s[1] - '0'][from_letter_to_number(s[0])] = 1;
	}

	cin >> s;
	row = s[1] - '0';
	column = from_letter_to_number(s[0]);

	options[row][column] = 1;
	
	for (int i = row + 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			if (positions[i][j]) options[i][j] += options[i - 1][j - 1] + options[i - 1][j + 1];
			else options[i][j] = options[i - 1][j];
		}
	}

	int total_options = 0;

	for (int i = 1; i <= size; i++)
		total_options += options[size][i];

	cout << total_options << '\n';

}