#include <iostream>
#include <string>
/*
���մ���������Ķ�˳�򣬴�ӡ�������ظ����ֵ��µ�����

��������
9876673
�������
37689
*/
using namespace std;
string& f(string& str1, string& str2) {
	if (str1.empty())
		return str2;
	char c = str1.back();
	int index = str2.find_first_of(c);
	if (index >= 0 && index < str2.size()) {
		return f(str1=str1.substr(0, str1.size() - 1), str2);
	}
	else {
		return f(str1=str1.substr(0, str1.size() - 1), str2.append(string(1,c)));
	}
}
int main() {
	int i;
	cin >> i;
	string str1 = to_string(i);
	string str2 = "";
	cout << f(str1,str2) << endl;;
}