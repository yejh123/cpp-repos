#include <iostream>
using namespace std;
int main()
{
	int i1 = 1;
	for (; i1 <= 3000; ++i1)
	{
		int sum1 = 0;
		for (int t = 1; t <= i1 / 2; ++t)
		{
			if (i1 % t == 0)
				sum1 += t;
		}
		//cout << sum1 << endl;
		int i2 = 1;
		
		for (; i2 < i1; ++i2)
		{
			int sum2 = 0;
			for (int t = 1; t <= i2 / 2; ++t)
			{
				if (i2 % t == 0)
					sum2 += t;
			}
			if (sum1 == i2  && sum2 == i1)
				cout << "(" << i2 << "," << i1 << ")";
		}
		
	}
}