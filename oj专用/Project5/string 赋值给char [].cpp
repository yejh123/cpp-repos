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
	sstr << s;//��s��ֵ�ŵ�stringstream
	sstr >> ch[0];//��stringstream�е�ֵ������ch
	cout << ch <<'\n'<<ch[0]<< endl;
	return 0;
}