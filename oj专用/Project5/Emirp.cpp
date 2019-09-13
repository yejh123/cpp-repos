#include<iostream>
#include<cmath>
using namespace std;
//翻转
int f(int i)
{
	int a[10];
	int result = 0, t;
	for (t = 0; i != 0; ++t)
	{
		a[t] = i % 10;
		i /= 10;
	}
	int n = t - 1;
	for (t = 0; t <= n; ++t)
	{
		result += a[t] * pow(10.0, n - t);
	}
	return result;
}
//检查是否素数
bool f2(int i)
{
	int t;
	bool bl = 1;
	for (t = 2; t <= sqrt(double(i)); ++t)
	{
		if (i % t == 0)
		{
			bl = 0;
		}
	}
	return bl;
}
int main()
{
	int n;
	while (cin >> n)
	{
		int t2 = 1;
		cout << 2;
		for (int i = 3, t2 = 1; t2 < n; ++i)
		{
			int i2 = f(i);
			if (f2(i) && f2(i2))
			{
				if (t2 % 10 == 0)
				{
					cout << endl << i;
				}
				else
					cout << " " << i;
				++t2;
			}
		}
		if (t2 % 10 != 0)
			cout << endl;
	}
}

/**************************************************************
	Problem: 3270
	User: 201830582180
	Language: C++
	Result: 正确
	Time:0 ms
	Memory:1492 kb
****************************************************************/