#include <iostream>
#include <string>
#include <deque>
using namespace std;
int main()
{
	string s;
	deque<string> d;
	while (cin >> s) {
		d.push_back(s);
	}
	for (deque<string>::iterator it = d.begin(); it != d.end(); ++it) {
		cout << *it << " ";
	}
		cout << endl;
	
}
