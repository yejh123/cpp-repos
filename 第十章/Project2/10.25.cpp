#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;
bool check_size(const string &s1,unsigned sz) {
	return s1.size() <sz;
}

void biggies(vector<string> &vs, unsigned i)
{
	//vector<string> vs{ "dasf","ajs","fajo","jha","hjaf9hp","s","ajs","fihaos", "jha","dasho","dhas","fajo" };
	for (auto a : vs)
		cout << a << " ";
	cout << vs.size() << endl;

	sort(vs.begin(), vs.end());
	auto it = unique(vs.begin(), vs.end());
	vs.erase(it, vs.end());

	//auto f = bind(check_size, _1, i);
	auto it1 = stable_partition(vs.begin(), vs.end(), bind(check_size, _1, i) ); //����Զ���Ϊ"��С��С��i���С�����ڵ���i"
	for (auto a : vs)
		cout << a << " ";
	cout << vs.size() << endl;

	//auto it1 = find_if(vs.begin(), vs.end(), [i](const string & s) {return s.size() >= ; });
	cout << "���ڵ���5�ĵ�����" << vs.end() - it1 << "��" << endl;
	while (it1 != vs.end()) {
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;
}
int main()
{
	vector<string> vs{ "dasf","ajs","fajo","jha","hjaf9hp","s","ajs","fihaos", "jha","dasho","dhas","fajo" };
	biggies(vs, 5);
}