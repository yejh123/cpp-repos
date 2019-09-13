#include <iostream>
using namespace std;
class Integer {
	void operator+(const Integer& i) {
	}
};
int main() {
	char c;
	while (cin >> c) {
		short s1, s2;
		cin >> s1 >> s2;
		if (c == '+') {
			cout << s1 + s2 << endl;
		}
		else if (c == '-') {
			cout << s1 - s2 << endl;
		}
		else if (c == '*') {
			cout << s1 * s2 << endl;
		}
		else if (c == '/') {
			cout << s1 / s2 << endl;
		}
	}
}