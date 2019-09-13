#include <iostream>
#include <string>
#include <list>
#include <forward_list>
#include <vector>
using namespace std;
void f(string &s, string oldval, string newval) {
	unsigned u = 0;
	for (unsigned t = 0; t<s.size();++t) {
		
		 t = s.find(oldval,u);
		if (t < s.size()) {
			string::iterator it2 = s.begin() + t;
			it2 = s.erase(it2, it2 + oldval.size());
			s.insert(it2, newval.begin(), newval.end());
			u = u + newval.size();
		
		}
		else break;
	}
	cout << s << endl;
}
int main()
{
	string s1 = "tho tho thru",s2 = "thru tho thru";
	f(s1, "tho","though");
	f(s2, "thru","through");
}