#include<iostream>
#include<cmath>
using namespace std;
struct point
{
	int x;
	int y;
};
int main()
{
	for(int i = 1 ; i <= 3; ++i)
	{
		point p;
		point a[4];
		int t = 0;
		while (t<4 && cin >> p.x >> p.y)
		{
			a[t++] = p;
			
		}
		int x1 = abs(a[0].x - a[1].x);
		int y1 = abs(a[0].y - a[1].y);
		int x2 = abs(a[2].x - a[3].x);
		int y2 = abs(a[2].y - a[3].y);
		if ((x1 == x2 && y1 == y2) || (x1 == y2 && x2 == y1))
		{
			cout << "yes" << endl;

		}
		else
			cout << "no" << endl;
	}
}