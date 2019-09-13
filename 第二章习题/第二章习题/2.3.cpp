#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
	int i;
	while (cin >> i)
	{
		int sum = 0;
		for (int j = 1; j <= i / 2; ++j)
		{
			if (i % j == 0)
			{
				sum += j;
			}
		}
		cout << (sum == i) << endl;
	}
}