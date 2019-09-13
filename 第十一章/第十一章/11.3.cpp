#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;
string &trans(string &s) {
	for (int p = 0; p != s.size(); ++p) {
		cout << int(s[p]) << " ";
		
		if (s[p] >= 'A' &&s[p] <= 'Z')
			s[p] = s[p] - 'A' + 'a';
		else if (s[p] == ',' || s[p] == '.')
			s.erase(p,1);

	}
	
	cout << endl;
	return s;
}
int main() {
	
	map<string, int> m;
	string word;
	ifstream in("data.txt");
	while (in >> word) {
		trans(word);
		++m[word];
	}
	for (auto p : m) {
		cout << p.first << "出现了" << p.second << "次" << endl;
	}
}