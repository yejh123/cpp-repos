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
	//Person p;                       //放在while内？ 必须要放在while内，否则phones涵盖上一个人的
	string line, phone;
	while (getline(ift, line)) {
		Person p;
		ist.clear();                  //重复使用字符串流时，每次都要调用clear
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