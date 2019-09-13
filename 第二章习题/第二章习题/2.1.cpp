#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int i;
	while (cin >> i)
	{
		for (int a = 2; a <= sqrt(i); )
		{
			if (i % a == 0)
			{
				cout << a << endl;
				i /= a;
				a = 2;
			}
			else ++a;
		}
		cout << i << endl;
	}
}