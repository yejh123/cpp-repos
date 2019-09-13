#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;
template <typename I,typename T>
I find1(I b, I e, const T &v)
{
	while (b != e && *b != v) {
		
		++b;
	}
	return b;
}
int main()
{
	vector<int> vi {1,2,3,4,5,6};
	list<string> ls{ "nfp","fnndgp","nas","wffs" };
	string s0 = "dao";
	auto iter = find1(ls.begin(), ls.end(), "nfp");
	cout << *iter << endl;
}