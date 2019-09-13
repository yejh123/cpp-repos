#include <iostream>
#include<functional>
#include <string>
#include <map>
using namespace std;
int main()
{
	map<char, function<int(int, int)>> binops{
		{'+',plus<int>()},
	{'-',minus<int>()},
	{'*',multiplies<int>()},
	{'/',divides<int>()},
	{'%',modulus<int>()},
	{'^',[](int i, int n) { return pow(i,n); } }
	};
	char c;
	int i1, i2;
	
	while (cin>>i1>>c>>i2)
	{
		cout << binops[c](i1, i2) << endl;
	}
}