#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	string  s1= "a" ,s2 = "b",s3 = "c",s4,s5,s6;
	istringstream ist;
	getline(cin,s4);
	cout << s4 << endl;;
	cout << ist.fail() << " " << ist.rdstate() << " " << ist.good() << endl;
	cin >> s5;
	ist.str(s5);
	ist >> s6;
	cout << s6 << endl;


}