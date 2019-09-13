#include <iostream>
#include <string>
#include <list>
#include <forward_list>
#include <vector>
using namespace std;
/*
int main()
{
	string s("ab2c3d7R4E6");
	unsigned t = 0;
	while (t!=s.size()) {
		auto t2 = s.find_first_of("0123456789", t);
		t=t2+1;
		cout << s[t2] << endl;
	}
}
*/
int main() {
	string s("ab2c3d7R4E6");
	unsigned t = 0;
	while (t != s.size()) {
		auto t2 = s.find_first_not_of("abcdRE", t);
		t = t2 + 1;
		cout << s[t2] << endl;
	}
	string a = "123";
	cout << a.find("a") << endl;
}