#include <iostream>
using namespace std;
int get_count(int num)
{
	int count = 0;
	while (num != 0)
	{
		num /= 10;
		++count;
	}
	return count;
}
int get_i(int num, int n)
{
	int i;
	for (int t = 1; t <= n; ++t)
	{
		i = num % 10;
		num = num / 10;
		
	}
	return i;
}
int main()
{
	int num;
	while (cin >> num)
	{
		int count = get_count(num);
		bool bl = 1;
		for (int t = 1; t <= count / 2 ; ++t)
		{
			int i1, i2;
			i2 = get_i(num, t);
			i1 = get_i(num, count - t + 1);
			if (i1 != i2)
			{
				bl = 0;
				break;
			}
		}
		if (bl)
			cout << "1" << endl;
		else cout << "0" << endl;
	}
}