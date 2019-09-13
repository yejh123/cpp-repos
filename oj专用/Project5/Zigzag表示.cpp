#include<iostream>
#include <string>
#include<cstdlib>
#include<sstream>
using namespace std;
//qwertyuiopasdfghjklzxcvbnm
int main()
{
	string s;
	while (cin >> s)
	{
		stringstream ss;
		int n;
		cin >> n;
		string s1(250, '@');
		ss << s1;
		char a[5][50];
		ss >> a[0];
		int t1 = 1,t2,row,col = 0;
		a[0][0] = s[0];
		while (t1 < s.size())
		{
			for (row = 1; t1 < s.size() && row < n; ++row, ++t1)
			{
				a[row][col] = s[t1];
			}
			++col;
			for (row = n - 2; t1 < s.size() && row >= 0; --row, ++t1, ++col)
			{
				a[row][col] = s[t1];
			}
			if (row < 0)
			{
				--col;
			}
		}
		for (row = 0; row < n; ++row)
		{
			for (t2 = 0; t2 < 50; ++t2)
			{
				if (a[row][t2] != '@')
					cout << a[row][t2];
			}
			
		}
		cout << endl;
	}
}