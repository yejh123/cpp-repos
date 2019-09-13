#include<iostream>
using namespace std;
int main()
{
	int num, n, x, y, z, a, b;
	while (cin >> num)
	{
		for (int i = 1; i <= num; ++i)
		{
			cin >> n >> x >> y >> z >> a >> b;
			int ele, walk, shorter;
			if (z == 0)
			{
				shorter = x + y;
			}
			else
			{
				ele = n * 2 + b * (z - 1) + n - x + n - y;
				walk = a * (z - 1) + x + y;
				shorter = ele < walk ? ele : walk;
			}
			cout << shorter << endl;
		}
	}
}