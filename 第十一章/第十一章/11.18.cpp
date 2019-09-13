#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <typeinfo>
using namespace std;
int main()
{
	map<string, int> m{ {"fuck",1}, {"you",2} };
	set<string> s{ "daf","fapj" };
	auto it = s.begin();
	for (; it != s.cend(); ++it) {
		cout << *it << endl;
	}
	//cout << typeid(it).name() << endl;
}