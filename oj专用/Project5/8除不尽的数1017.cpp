#include <iostream>
using namespace std;
int main()
{
	int i = 0;
	for (; i <= 2000; ++i)
	{
		int a1 = i / 8, b1 = i % 8, a2 = a1 / 8, b2 = a1 % 8, a = a2 / 8, b3 = a2 % 8;
		int c1 = i / 17, d1 = i % 17, c2 = c1 / 17, d2 = c1 % 17;
		if (b1 == 1 && b2 == 1 && b3 == 7 && d1 == 4 && d2 == 15 && c2 == 2 * a)
			cout << i;
	}
}