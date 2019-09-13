#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;
int main()
{
	
	list <const char*> l = { "sb","chang" ,"shi","sb"};
	vector<string> v;
	v.assign({ "sb","chang" ,"shi","sb" });        //À¨ºÅÄÚ¸ÄÎªl.begin(),l.end()
	for (auto a : v)
		cout << a << endl;
	cout << v.capacity() << " " << v.size() << " " << v[0] << " " << v[v.size() - 1] << endl;
}