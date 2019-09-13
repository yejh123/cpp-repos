#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string s;
	int count;
	while (cin >> s)
	{
		
		string s0 = "baohua";
		string::iterator it, beg;
		for (it = s.begin(); it != s.end(); ++it)
		{
			if (isupper(*it))
				*it = tolower(*it);
		}
		beg = s.begin();
		count = 0;
		do
		{
			 it = search(beg, s.end(), s0.begin(), s0.end());
			 if (it != s.end())
			 {
				 ++count;
				 beg = it + 6 ;
			 }
		} while (it != s.end());
		cout << count << endl;

	}
}