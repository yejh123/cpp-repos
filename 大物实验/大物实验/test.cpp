#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> v= { 1,2,3,4,5,6 };
	v.erase(v.begin());
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << endl;
		if (*it == 5)
			v.erase(it);
	}
	for (auto it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << endl;
	}
}