#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct per
{
	int num;
	string name;
	char sex;
	int pay;
	int ret;
};

bool f(per p1, per p2)
{
	int a = p1.pay - p1.ret;
	int b = p2.pay - p2.ret;
	return a > b ? 1 : 0;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int i;
		per *a = new per[n];
		//输入数据
		for (i = 0; i < n; ++i)
		{
			cin >> a[i].num >> a[i].name >> a[i].sex >> a[i].pay >> a[i].ret;
		}
		//sort(a, a + n, f);                 //sort算法：按照实际消费（付款-退款）从大到小排序
		//按冒泡排序
		for (i = 0; i < n - 1; ++i)
		{
			for (int t = 0; t < n - i - 1; ++t)
			{
				int x = a[t].pay - a[t].ret;
				int y = a[t + 1].pay - a[t + 1].ret;
				if (x < y)
				{
					swap(a[t], a[t + 1]);
				}
			}
		}
		//统计男女生总计实际消费金额
		int M = 0, W = 0;
		for (i = 0; i < n; ++i)
		{
			if (a[i].sex == 'M')
			{
				M += a[i].pay - a[i].ret;
			}
			else
			{
				W += a[i].pay - a[i].ret;
			}
		}
		cout << 'M' << M << " " << "W" << W << endl;
		//遍历输出
		for (i = 0; i < n; ++i)
		{
			if (a[i].ret >= a[i].pay / 2)
			{
				cout << a[i].num;
			}
			cout << a[i].name << " ";
		}
		cout << endl;
	}
}