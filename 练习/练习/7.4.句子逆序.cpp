#include<iostream>
#include<string>
using namespace std;
string f(string s1, string s2) {
	int index = s1.find_last_of(' ');
	if (index > 0 && index < s1.size()) {
		return f(s1.substr(0, index), s2.append(s1.substr(index + 1, s1.size()) + " "));
	}
	else return s2 + s1;
}
int main() {
	string s;
	getline(cin, s);
	string s2;
	cout << f(s, s2) << endl;
}