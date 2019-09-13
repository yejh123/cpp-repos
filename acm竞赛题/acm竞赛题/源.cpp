#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	while (1)
	{
		double x1, y1, x2, y2, x3, y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		double a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)), b = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2)), c = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
		double p = (a + b + c) / 2;
		double s = sqrt(p * (p - a)* (p - b) * (p - c));
		cout << fixed << setprecision(3) << s << endl;
	}
}