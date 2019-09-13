#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main()
{
	multiset<int> si;
	int i;
	
	for (int t = 0; t != 10 && cin >> i; ++t)
	{
		si.insert(i);

	}
	while (cin >> i)
	{
		vector<int> vi;
		set<int>::iterator it, it2, beg;
		it = si.begin();
		for (beg = si.begin(); beg != si.end(); ++beg)
		{
			if (*it < *beg)
			{
				it = beg;
			}
		}
		if (i > *it);
		else {
			si.erase(it);
			si.insert(i);
		}
		for (it2 = si.begin(); it2 != si.end(); ++it2)
		{
			vi.push_back(*it2);
			
		}
		for (vector<int>::iterator it3 = vi.begin(); it3 != vi.end()-1; ++it3)
		{
			cout << *it3 << " ";
		}
		cout << *--vi.end() << endl;

	}
}