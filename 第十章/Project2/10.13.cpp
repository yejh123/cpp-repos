#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool f(const string &s) {
	return s.size() >= 5;
}
int main()
{
	vector<string> vs{"asdfgfg", "asd", "eyy", "jyeds", "DD", "aaf", "�ǵ���", "��i","fauihpaf","�ڰ�"};
	auto it = partition(vs.begin(), vs.end(), f);
	for (auto a : vs)
		cout << a << " ";
	cout << endl;
	for (auto i = vs.begin(); i != it; ++i)
		cout << *i << " ";
	cout << endl;
}
