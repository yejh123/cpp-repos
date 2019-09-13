#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
struct Person {
	string name;
	vector<string> phones;
	void getphone() {
		cout << this->name << " ";
		for (auto a : phones)
			cout << a << " ";
		cout << endl;
	}
};



int main()
{
	ifstream ift("data");
	istringstream  ist;
	vector<Person> people;
	//Person p;                       //����while�ڣ� ����Ҫ����while�ڣ�����phones������һ���˵�
	string line, phone;
	while (getline(ift, line)) {
		Person p;
		ist.clear();                  //�ظ�ʹ���ַ�����ʱ��ÿ�ζ�Ҫ����clear
		ist.str(line);
		ist >> p.name;
		while (ist >> phone) {
			p.phones.push_back(phone);
		}
		people.push_back(p);
	}
	for (auto a : people) {
		a.getphone();
	}
	return 0;
}