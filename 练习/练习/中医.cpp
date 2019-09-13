#include<fstream>
#include <string>
#include<iostream>
#include <random>
#include <ctime>
using namespace std;
int main() {
	string s;
	fstream out, in;
	out.open("C:\\学习\\java\\67.txt", ios::out);
	in.open("C:\\学习\\java\\in.txt", ios::in);
	if (!in || !out) cout << "file fail";
	srand(unsigned(time(0)));
	string a[9] = { "中医内科", "中医内科","中医内科","中医内科","中医外科", "中医妇科", "中医儿科","中医养生","针灸推拿" };
	while (in) {
		getline(in, s, '\t');
		out << s << '\t';
		string ss = a[rand() % 9];
		out << ss << '\t';
		getline(in, s, '\n');
		out << s << endl;
	}
	in.close();
	out.close();
}
