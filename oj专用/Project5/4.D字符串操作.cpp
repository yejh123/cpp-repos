#include <iostream>
#include <string>
using namespace std;
int main()
{
	string S;
	while (cin >> S)
	{
		string s1;
		while (cin >> s1)
		{
			if (s1 == "ADD")
			{
				string s11;
				int x;
				cin >> s11 >> x;
				S.insert(x + 1, s11);
				cout << S << endl;
			}
			if (s1 == "DEL")
			{
				int x, n;
				cin >> x >> n;
				S.erase(x, n);
				cout << S << endl;
			}
			if (s1 == "SER")
			{
				string s31;
				cin >> s31;
				cout << S.find(s31) << endl;
			}
			if (s1 == "CHA")
			{
				string s41;
				int x;
				cin >> s41 >> x;
				S.replace(x, s41.size(), s41);
				cout << S << endl;
			}
		}
	}
}