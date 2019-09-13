#include <iostream>
using namespace std;
int main()
{
	int n, m;
	while (cin >> m >> n)
	{
		int M = 1, N = 1, MN = 1;
		for (int t = 1; t <= m; ++t)
		{
			M *= t;

		}
		for (int t = 1; t <= n; ++t)
		{
			N *= t;

		}
		for (int t = 1; t <= m - n; ++t)
		{
			MN *= t;

		}
		cout << M / (N * MN) << endl;
	}
}