#include <iostream>
#include <string>
using namespace std;
int main()
{
	int i;
	string s = "                                        ";
	while (cin >> i)
	{
		for (int t1 = 1; t1 <= i; ++t1)
		{
			cout << s.substr(0, t1 - 1);
			for (int t = i; t >= 1; --t)
			{
				cout << t;
			}
			cout << endl;
		}
	}
}