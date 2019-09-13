#include <iostream>
#include <map>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int i;
		map<int, int, greater<int> > mi;
		int count;
		
		for ( count = 1; count <= n && cin>> i; ++count)
		{
				mi.insert(pair<int, int> (i, count));
		}
			
		typedef map<int, int, greater<int> >::iterator iterator;
		int t = 1;
		cout << n << endl;
		for (iterator it = mi.begin() ; it != mi.end(); ++it, ++t)
		{
			cout << it->first;
			if (t != n)
				cout << " ";
		}
		cout << endl;
		t = 1;
		for (iterator it = mi.begin() ; it != mi.end(); ++it, ++t)
		{
			cout << it->second - 1;
			if (t != n)
				cout << " ";
		}
		cout << endl;
	}
}