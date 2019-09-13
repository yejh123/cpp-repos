#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
using namespace std;
void print_map(map<string, string> m) {
	for (auto a : m)
		cout << a.first << " " << a.second << endl;
}
void trans(const string &s, map<string, string> m) {
	map<string, string>::iterator it;
	if ( (it = m.find(s) ) == m.end())
		cout << s;
	else cout << it->second;
}
map<string, string>  buildMap(istream &in) {
	map<string, string> m;
	string line,word1,word2;
	while (getline(in, line)) {
		istringstream is(line);
		while (is >> word1,getline(is,word2)) {
			m[word1] = word2.substr(1);
		}
	}
	print_map(m);
	return m;
}

void word_transform(istream &map_file,istream &input)
{
	string line,word;
	auto m = buildMap(map_file);
	while (getline(input, line)) {
		istringstream is(line);
		while (is >> word) {
			trans(word, m);
			cout << " ";
		}
		cout << endl;
	}

}



int  main()
{
	ifstream in("map_file.txt"), input("input.txt");
	if (!in) {
		cout << "没有map文件" << endl;
		exit(1);
	}
	if (!input) {
		cout << "没有input文件" << endl;
		exit(1);
	}
	map<string, string> m;
	word_transform(in, input);
	print_map(m);
}