#include<fstream>
#include <string>
#include<iostream>
#include <random>
#include <ctime>
using namespace std;
int main() {
	string s;
	fstream out, in;
	out.open("C:\\ѧϰ\\java\\67.txt", ios::out);
	in.open("C:\\ѧϰ\\java\\in.txt", ios::in);
	if (!in || !out) cout << "file fail";
	srand(unsigned(time(0)));
	string a[9] = { "��ҽ�ڿ�", "��ҽ�ڿ�","��ҽ�ڿ�","��ҽ�ڿ�","��ҽ���", "��ҽ����", "��ҽ����","��ҽ����","�������" };
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
