#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	int n, m;
	while (cin >> n)
	{
		int t = 1;
		while (t <= n && cin >> m)
		{
			++t;
			double *px = new double[m], *py = new double[m];
			int i;
			double S = 0, x, y;
			for (i = 0; i < m; ++i)
			{
				cin >> x >> y;
				px[i] = x, py[i] = y;
			}
			for (i = 0; i < m - 1; ++i)
			{
				S += px[i] * py[i + 1] - px[i + 1] * py[i];
			}
			S += px[m - 1] * py[0] - px[0] * py[m - 1];
			cout << fixed << setprecision(2) << fabs(S/2) << endl;
		}
	}
}