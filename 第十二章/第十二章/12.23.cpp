#include <iostream>
#include <string>
#include <memory>
using namespace std;
int main()
{
	const char *c1 = "sb";
	const char *c2 = "chang";
	char *p = new char[strlen(c1)+strlen(c2)+2];
	strcpy(p, c1);
	strcat(p, c2);
	cout << p << endl;

	string s1 = "chongming", s2 = "heng";
	strcpy(p, (s1 + s2).c_str());
	cout << p << " " << strlen(p);

}