#include <iostream>
#include <string>
#include <deque>
#include <forward_list>
#include <vector>
using namespace std;
void f(forward_list<string> &fls, string s1, string s2) {         //&不能缺失！！！string可改为const string&
	auto it = fls.begin(),it2 = fls.before_begin();
	bool bl = 0;
	while (it != fls.end()) {
		if (*it == s1) {
			it = fls.insert_after(it, s2);
			bl = 1;
		}
		++it; ++it2;
	}
	if (!bl)
		fls.insert_after(it2 , s2);

}
int main()
{
	forward_list<string> fls{ "s","chang","shi","s" };
	f(fls, "s", "b");
	for (auto a : fls)
		cout << a << " ";
		cout << endl;
}