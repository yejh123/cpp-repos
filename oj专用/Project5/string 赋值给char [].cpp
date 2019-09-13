#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main(int argc, char *argv[])
{
	stringstream sstr;
	sstr.clear();
	//char * ch = new char[1024];
	char ch[1024][2];
	string s = "abcd";
	sstr << s;//将s的值放到stringstream
	sstr >> ch[0];//将stringstream中的值导出到ch
	cout << ch <<'\n'<<ch[0]<< endl;
	return 0;
}