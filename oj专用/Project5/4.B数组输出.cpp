#include <iostream>
#include <map>
using namespace std;
int main()
{
	map<int,int> mi;
	int i;

	for (int t = 0; t != 10 && cin >> i; ++t)
	{
		mi.insert(pair<int,int>(i, t));
	}
	map<int, int>::iterator it;
	for (it = --mi.end(); it != mi.begin(); --it)
	{
		cout << it->first << " " << it->second << endl;
	}
	
	cout << mi.begin()->first << " " << mi.begin()->second << endl;

	
}