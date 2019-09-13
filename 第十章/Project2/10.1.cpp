#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
using namespace std;
int main()
{
	const char *c[]{ "dsa","das","ojafsd","fdah","hai","dsa" };
	list<string> ls{ "dsa","das","ojafsd","fdah","hai","dsa" };
	vector<int> v{ 132,15,65421,65,1,4,41,254,1,4,54,4545,4,545,48,6,98756,546,65,464,5654 };
	cout << count(cbegin(c),cend(c), "dsa")<<endl;
	cout << count(ls.cbegin(), ls.cend(), "dsa");

}