#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	double x, y;
	while (cin >> x)
	{
		y = sinh(1 + sinh(x)) / (sinh(2 * x) + sinh(3 * x));
		cout << fixed << setprecision(4) << y << endl;
	}
}