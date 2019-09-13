#include <iostream>
#include <iomanip>
using namespace std;
/*float p(double x, int n)
{
	double t1, t2;
	if (n == 0)
		return 1;
	else
		if (n == 1)
			return x;
		else
		{
			t1 = (2 * n - 1)*p(x, n - 1);
			t2 = (n - 1)*p(x, n - 2);
			return (t1 - t2) / n;
		}
}*/
double p(double x, int n)  
{
	if (!n)
	{
		return 1;
	}
	if (n == 1)
	{
		return x;
	}
	if (n > 1)
	{
		
		return ((2 * n - 1)* p(x, n - 1) - (n - 1) * p(x, n - 2)) / n;
	}
}

int main()
{
	double x;
	int n;
	while (cin >> x >> n)
	{
		cout << fixed << setprecision(4) << p(x, n) << endl;

	}
}