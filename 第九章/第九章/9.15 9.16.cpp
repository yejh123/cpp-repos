#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;
bool f(list<int> l, vector<int> v) {
	if (l.size() != v.size())
		return false;
	auto it1 = l.begin(),it2 = l.end();
	auto it3 = v.begin();
	while (it1 != it2) {
		if (*it1 != *it3)
			return false;
		++it1, ++it3;
	}
	return true;
}
//9.16
int main()
{
	list<int> l{ 1,2,3 };
	vector<int> v{1, 2, 4};
	if (l < v) {

	}
	cout << f(l, v) << endl;
}
/*              9.15
int main()
{
vector<int> v1{ 1,2,3 };
vector<int> v2{ 1,2,3 };
v1.push_back(4);
cout << v1.capacity() << " " << v1.size() << endl;
v1.pop_back();
cout << v1.capacity() << " " << v1.size() << endl;
if (v1 == v2)
cout << "success" << endl;
else cout << "failure" << endl;

}
*/