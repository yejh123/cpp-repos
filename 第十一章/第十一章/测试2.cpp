#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
int main() {
	map<int, int> m{ {1,2}, {4,5} ,{10,54},{66,12} };
	int i= 67;
	auto it1 = m.lower_bound(i);
	cout << (it1)->second << endl;;
	auto it2 = m.upper_bound(i);
	cout << it2->second << endl;
	auto p = m.equal_range(i);
	cout << p.first->second << " " << p.second->second << endl;
}