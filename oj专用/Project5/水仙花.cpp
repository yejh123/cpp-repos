#include <iostream>
using namespace std;
int main()
{
	int a1 = 0, a2 = 0, a3 = 0;
	for (int i = 100; i <= 999; ++i)
	{
		a1 = i / 100;
		a2 = i % 100 / 10;
		a3 = i % 10;
		if (i == a1 * a1 * a1 + a2 * a2 * a2 + a3 * a3 * a3)
			cout << i << " ";
	}
	cout << endl;
	return 0;
}