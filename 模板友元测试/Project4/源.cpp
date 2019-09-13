#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str1,str2;
	bool bl = false;
	while (cin >> str2)
	{
		if (!isupper(str2[0]))
			continue;
		if (str1 == str2)
		{
			cout << str2 << endl;
			bl = 1;
			break;
		}
		str1 = str2;
	}
	if (!bl)
		cout << "没有任何单词是重复出现的" << endl;
	return 0;
}