#include <iostream>
#include <string>
#include <list>
#include <forward_list>
#include <vector>
using namespace std;
void f(string &s, const string &oldval, const string &newval) {
	unsigned t = 0,p = 0;
	while ( ( p = s.find(oldval,p) ) != string::npos) {
	
		s.replace(p, oldval.size(), newval);
		p = p + newval.size();
		
	}
	cout << s << endl;
}
int main()
{
	string s1 = "tho tho thru", s2 = "thru tho thru";
	f(s1, "tho", "though");
	f(s2, "thru", "through");
}
