#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
using namespace placeholders;
void print(ostream &os,const string &s,char c) {
	cout << s << c;
}
int  main()
{
	vector<string> vs{"fhua", "fdhas", "hsdo", "fuck", "your","mother"};
	ofstream ofs("output1");
	char c = ' ';
	for_each(vs.crbegin(), vs.crend(), bind(print,ref(ofs),_1,c));



}