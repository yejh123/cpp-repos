#include <iostream>
#include <string>
#include <list>
#include <forward_list>
#include <vector>
using namespace std;
int main()
{

	vector<char> vc;
	string s1 = "sbchang";
	char c[] = "sb chang";
	for (auto a : s1) {
		vc.push_back(a);
	}
	string s2;
	s2.assign(c);               //���Բ��õڶ�������
	//s2.assign(vc.data(),vc.size());         //����Ҫ�еڶ�������
	/*
	for (auto a : vc)
		s2.push_back(a);
		*/
	cout << s2 << " " << s2.size() << " " << s2.capacity() << endl;
}

