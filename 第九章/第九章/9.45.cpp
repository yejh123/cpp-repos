#include <iostream>
#include <string>
#include <list>
#include <forward_list>
#include <vector>
using namespace std;
string & f(string& name, const string & front = "sb", const string &back = "shi da sb") {
	name.insert(0, " ");
	name.insert(0, front);
	
	//name.append(back);
	
	name.insert(name.size(), " ");
	name.insert(name.size(), back);
	return name;
}
int main() {
	string s = "chang";
	f(s);
	cout << s << endl;
}