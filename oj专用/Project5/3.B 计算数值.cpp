#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	int m, n, p;
	while (cin >> m >> n >> p)
	{
		double M = 0, N = 0, P = 0;
		double result = 0;
		for (int i1 = 1; i1 <= m; ++i1)
		{
			M += i1;
		}
		for (int i2 = 1; i2 <= n; ++i2)
		{
			N += pow(i2, 3);
		}
		for (int i3 = 1; i3 <= p; ++i3) 
		{
			P += pow(i3, 5);
		}
		result = (M + N) / P;
		cout <<fixed<<setprecision(4)<< result << endl;
	}
}