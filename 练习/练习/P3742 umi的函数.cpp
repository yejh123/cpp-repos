#include <iostream>
#include<string>
using namespace std;
string f(int n,char X[], char Y[])
{
	string s;
	for (int i = 0; i < n; ++i)
	{
		char x = X[i], y = Y[i];
		if (x < y)
		{
			return string();
		}
		if (x == y)
		{
			s += x;
		}
		else
		{
			s += y;
		}
	}
	return s;
}
int main()
{
	char X[100], Y[100];
	int n;
	while (cin >>n>> X >> Y)
	{
		if (!(f(n, X, Y).size()))
		{
			cout << -1 << endl;
		}
		else
			cout << f(n, X, Y) << endl;
	}
}