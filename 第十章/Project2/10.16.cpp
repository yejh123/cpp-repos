#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool f(string s1, string s2) {
	return s1.size() < s2.size();
}
int main()
{
	vector<string> vs{ "dasf","ajs","fajo","jha","hjaf9hp","s","ajs","fihaos", "jha","dasho","dhas","fajo"};
	for (auto a : vs)
		cout << a << " ";
	cout <<vs.size()<<endl;
	sort(vs.begin(), vs.end());
	auto it = unique(vs.begin(), vs.end());
	vs.erase(it, vs.end());
	stable_sort(vs.begin(), vs.end(), f);
	for (auto a : vs)
		cout << a << " ";
	cout << vs.size() << endl;
	unsigned i = 5;
	auto it1 = find_if(vs.begin(), vs.end(), [i](const string & s) {return s.size() >= 5; });
	cout << "大于等于5的单词有" << vs.end() - it1 << "个" << endl;
	while (it1 != vs.end()) {
		cout << *it1<<" ";
		++it1;
	}
	cout << endl;


}