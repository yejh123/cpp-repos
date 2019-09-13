#include <iostream>
#include <string>
#include <deque>
#include <list>
#include <vector>
using namespace std;
int main()
{
	vector<int> v{ 1,2,3,4 };
	auto it1 = v.end()+1;
	vector<int>::iterator it2 = v.end()+1, it3;
	 v.erase(it1, it2);
	for (auto a : v)
		cout << a <<" ";
	cout << endl;
	//cout << *it3 << endl;

}