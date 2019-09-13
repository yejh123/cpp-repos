#include <iostream>
#include <string>
using namespace std;
string carry( string &s , int t )
{
	//int length = s.end() - s.begin() - 1;
	if (s[t - 1] == '9')
	{
		s[t - 1] = '0';
		if (s[0] != '0')
		{
			if (s[t - 2] == '9')
			{
				carry(s, t - 1);
			}
			else
			{
				s[t - 2]++;
			}
		}
		else
		{
			s =  "1" + s;
		}
	}
	else
	{
		int i = (int)s[t - 1] + 1;
		s[t - 1] = char(i);
	}
	return s;
}
int main()
{
	string s = "0";
	int t;
	while (1)
	{
		cout << s << endl;
		t = s.size();
	    carry(s, t);
	}
}