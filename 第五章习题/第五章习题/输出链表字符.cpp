#include<iostream>
#include<string>
using namespace std;
struct  list
{
	char c;
	list * next;
};
int main()
{
	string s;
	while (cin >> s)
	{
		string::reverse_iterator it = s.rbegin();
		for (; it != s.rend(); ++it)
		{
			cout << *it;
		}
		cout << endl;
	}
}