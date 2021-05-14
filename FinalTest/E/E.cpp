#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	long long sum  = 0;
	cin >> s;
	int l = s.length();
	long long* res_u = new long long[l];
	long long* res_d1 = new long long[l];
	long long* res_d2 = new long long[l];

	for (int i = 0; i < l; i++)
	{
		res_u[i] = 0;
		res_d1[i] = 0;
		res_d2[i] = 0;
	}

	for (int i = 0; i < l; i++)
	{
		if (s[i] == 'u')
			for (int j = 0; j < i; j++)
				if (s[j] == 'd') res_u[i] += res_d2[j];

		if (s[i] == 'd')
			for (int j = 0; j < i; j++)
			{
				if (s[j] == 'd') res_d2[i] += res_d1[j];
				if (s[j] == 'u') res_d1[i] += 1;
			}
	}

	for (int i = 0; i < l; i++)
	{
		if (s[i] == 'u') sum += res_u[i];
	}
	cout << sum << '\n';
}

