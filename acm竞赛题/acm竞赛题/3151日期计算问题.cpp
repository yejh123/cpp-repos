#include<iostream>
using namespace std;
int f(int i)
{
	if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0))
		return 366;
	else
		return 365;
}
int main()
{
	int a1[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int a2[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int year, month, day, diff ;
	while (cin >> year >> month >> day)
	{
		diff = 0;
		int t1 = 0, t2;
		if (year < 2018)
		{
			for (int i = year; i < 2017; ++i)
			{
				diff += f(i + 1);
			}
			if (f(year) == 365)
			{
				for (int i = 0; i < month - 1; ++i)
				{
					t1 += a1[i];
				}
				t1 += day;
				diff += 365 - t1 + 1;
			}
			else
			{
				for (int i = 0; i < month - 1; ++i)
				{
					t1 += a2[i];
				}
				t1 += day;
				diff += 366 - t1 + 1;
			}
			if (diff % 7 == 0)
				cout << 1 << endl;
			else
				cout << 8 - diff % 7 << endl;
		}
		else
		{
			for (int i = 2018; i < year; ++i)
			{
				diff += f(i);
			}
			if (f(year) == 365)
			{
				for (int i = 0; i < month - 1; ++i)
				{
					diff += a1[i];
				}
				diff += day - 1;
			}
			else 
			{
				for (int i = 0; i < month - 1; ++i)
				{
					diff += a2[i];
				}
				diff += day - 1;
			}
			cout << diff % 7 + 1 << endl;
		}
	}
}