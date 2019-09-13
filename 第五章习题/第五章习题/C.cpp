#include<iostream>
#include<cmath>
using namespace std;
struct point {
	double x;
	double y;

};
int main()
{
	point p1,p2,p3;
	while (cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y)
	{
		double a = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
		double b = sqrt((p1.x - p3.x) * (p1.x - p3.x) + (p1.y - p3.y) * (p1.y - p3.y));
		double c = sqrt((p3.x - p2.x) * (p3.x - p2.x) + (p3.y - p2.y) * (p3.y - p2.y));
		cout << a << " " << b << " " << c << endl;
		if (abs(a - b) < 1e-4 && abs(a - c) < 1e-4 && abs(b - c) < 1e-4)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
}