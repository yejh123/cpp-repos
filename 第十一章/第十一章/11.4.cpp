#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>
//#include <cctype>
using namespace std;
/*
string & trans(string &s) {
	for (auto &a : s) {
		if (isupper(a)) {
			a = tolower(a);
			
		}
		if (ispunct(a)) {
			a = ' ';
		}
	}
	return s;
}
*/

string &trans(string &s) {
	for (int p = 0; p != s.size(); ++p) {
		cout << int(s[p]) << " ";
		if (s[p] >= 'A' &&s[p] <= 'Z')
			s[p] = s[p] - 'A' + 'a';
		else if (s[p] == ',' || s[p] == '.')
			s.erase(p, 1);
		
	}
	return s;
}
int main() {
	ifstream in("data.txt");
	string s;
	//if (!in) {
	//	cout << "不存在文件" << endl;
	//	exit(1);
	//}
	while (cin >> s)
	{
		trans(s);
		cout << s << " ";
	}
}