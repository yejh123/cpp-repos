#include <iostream>
#include <string>
#include <list>
#include <forward_list>
#include <vector>
using namespace std;
int main()
{
	forward_list<int> fli{ 0,1,2,3,4,5,6,7,8,9 };
	auto it1 = fli.before_begin(),it2 = fli.begin();
	while (it2 != fli.end()) {
		if (*it2 & 1) {
			it1 = fli.insert_after(it2, *it2);
			++it2; ++it2;
		}
		else {
			it2 = fli.erase_after(it1);
		}
	}
	for (auto a : fli)
		cout << a << " ";
	cout << endl;
	
}