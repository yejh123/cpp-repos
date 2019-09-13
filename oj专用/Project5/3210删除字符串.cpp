#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string s1;
	while (getline(cin,s1))
	{
		string s2, s3;
		for (int i = 0; i < s1.size(); ++i)
		{
			int a = s1.find_first_of(s2);
			if (a == -1 || a > i)
			{
				s2 += s1[i];
				s3 += s1[i];
				
			}
			s1.erase(i, 1);
			--i;
		}
		cout << s3 << endl;
	}
}