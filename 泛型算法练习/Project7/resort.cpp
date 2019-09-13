/*
重排元素算法
C++ Primer P342
*/
#include "Chapter10.h"
void resort() {
	ifstream in("Text.txt");
	if (!in) {
		cerr << "文件不存在";
		return;
	}
	string line;
	getline(in, line);
	istringstream is(line);
	string s;
	vector<string> vec;
	while (is >> s) {
		vec.push_back(s);
	}
	sort(vec.begin(), vec.end());
	vector<string>::iterator end = unique(vec.begin(), vec.end());
	for (auto i = vec.begin(); i < end; ++i) {
		cout << *i << " ";
	}
	cout <<"最后:"<< *(vec.cend() - 1);
	cout << endl;
	for (auto i = vec.cbegin(); i < vec.cend(); ++i) {
		try {
			cout << *i << " ";
		}
		catch (exception e) {
			cout << "error" << endl;
		}
	}
	cout << endl;
	vec.erase(end, vec.end());
	for (auto i = vec.cbegin(); i < vec.cend(); ++i) {
		cout << *i << " ";
	}
	cout << endl;
}