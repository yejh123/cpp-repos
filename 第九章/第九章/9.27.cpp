#include <iostream>
#include <string>
#include <deque>
#include <forward_list>
#include <vector>
using namespace std;
int main()
{
	forward_list<int> fli{ 1,2,3,4,5,6,7,8,9 };
	auto it1 = fli.cbefore_begin(), it2 = fli.cbegin();
	while (it2 != fli.end()) {
		if(*it2 %2)
		    it2 = fli.erase_after(it1);
		else {
			it1 = it2;
			++it2;
		}
	}
	for (auto a : fli)
		cout << a << " ";
	cout << endl;
}