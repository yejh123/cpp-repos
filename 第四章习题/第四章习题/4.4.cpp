#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1, s2;
	int i;
	while (cin >> s1 >> s2 >> i)
	{
		s1.insert(i, s2);
		cout << s1 << endl;
	}
}