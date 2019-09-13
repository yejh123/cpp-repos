#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <list>
#include <string>
using namespace std;
int main() {
	ifstream in("data1.txt");
	string word,line;
	int linenum = 0;
	map<string, list<int> > m;
	while (getline(in, line)) {
		++linenum;
		istringstream sin(line);
		while(sin >> word)
		    m[word].push_back(linenum);
	}
	for (auto p : m) {
		cout << p.first << "出现在";
			for (auto a : p.second)
				cout << a << " ";
			cout << "行" << endl;
	}
}