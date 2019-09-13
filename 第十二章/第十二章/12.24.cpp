#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1;
	char *cp = new char[10];
	cin >> s1;
	strcpy(cp, s1.c_str());
	cout << cp<<" "<<strlen(cp) << endl;
}