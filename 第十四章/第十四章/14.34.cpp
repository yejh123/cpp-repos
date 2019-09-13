#include <iostream>
#include <string>
using namespace std;
struct A {
	string operator() (int i, string s1, string s2) {
		if (i)
			return s1;
		else return s2;
	}
};
int main() {
	A a;
	string s = a(-1, "success", "failure");
	cout << s << endl;
}