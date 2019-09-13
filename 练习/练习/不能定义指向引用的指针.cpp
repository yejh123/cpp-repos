#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
typedef vector<string&> type;
int main() {
	string str = "fdjia";
	string& ref = str;
	string str2 = "dajio";
	string* ptr = &ref;
	//string & * ref_ptr = &ref;		不能定义指向引用的指针
	string * & ptr_ref = ptr;			//可以定义指针引用
	cout << ptr << " " << *ptr << endl;
	cout << ptr_ref << " " << *ptr_ref << endl;

}