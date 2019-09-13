#include<iostream>
#include<iomanip>
#include <cmath>
using namespace std;
int main()
{
	int m, n, p;
	while (cin >> m >> n >> p)
	{
		int s1 = 0, s2 = 0, s3 = 0;
		for (int t = 1; t <= m; ++t)
		{
			s1 += t;
		}
		for (int t = 1; t <= n; ++t)
		{
			s2 += pow(t, 3);
		}
		for (int t = 1; t <= p; ++t)
		{
			s3 += pow(t, 5);
		}
		double s = double(s1 + s2) / s3;
		cout <<fixed<<setprecision(4)<<s << endl;
	}
}