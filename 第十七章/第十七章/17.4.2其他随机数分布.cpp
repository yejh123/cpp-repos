#include<iostream>
#include <string>
#include <random>
using namespace std;
int main() {
	default_random_engine e;
	uniform_real_distribution<> u(0, 1);    //默认模板实参为double
	for (int i = 0; i < 5; ++i)
	{
		cout << u(e) << " ";
	}
	cout << '\n' << "生成非均匀分布的随机数:" << endl;
	normal_distribution<> n(4, 1.5);
	vector<int> vals(9);
	for (int i = 0; i != 200; ++i)
	{
		unsigned v = lround(n(e));
		if (v < vals.size())
			++vals[v];
	}
	for (int i = 0; i != vals.size(); ++i)
	{
		cout << i << ":" << string(vals[i], '*') << endl;
	}
}
