#include <iostream>
#include <string>
#include <vector>
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
	bool bl = a > b ? 1 : 0;
	return bl;
}

int main()
{
	

		int n;
		while (cin >> n)
		{
			int i;
			per p;
			vector<per> v;
			for (i = 1; i <= n; ++i)
			{
				cin >> p.num >> p.name >> p.sex >> p.pay >> p.ret;
				v.push_back(p);
			}
			int M = 0, W = 0;

			sort(v.begin(), v.end(), f);
			vector<per>::iterator it;
			for (it = v.begin(); it != v.end(); ++it)
			{
				if (it->sex == 'M')
				{
					M += it->pay - it->ret;
				}
				else
				{
					W += it->pay - it->ret;
				}
			}
			cout << 'M' << M << " " << "W" << W << endl;
			for (it = v.begin(); it != v.end(); ++it)
			{
				if (it->ret >= it->pay / 2)
				{
					cout << it->num;
				}
				cout << it->name << " ";
			}
			cout << endl;
		}
		return 0;
		
}