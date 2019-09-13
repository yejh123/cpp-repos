#include <iostream>
#include <cmath>
using namespace std;
int ws(long long l)
{
	int n = 1;
	while (l >= 10)
	{
		++n;
		l /= 10;
	}
	return n;
}
long long f(long long l, long long r, int n)
{

	for (; l >= 10; )
	{
		int a = l % 10;
		l /= 10;
		r += a * pow(10, n - 1);
		--n;
	}
	r += l;
	return r;
}
int main()
{
	long long a, b;
	while (cin >> a)
	{
		b = 0;
		if (a >= 0)
		{
			int n = ws(a);
			b = f(a, b, n);
			if (b > 2147483647)
				cout << 0 << endl;
			else
				cout << b << endl;
		}
		if (a < 0)
		{
			a = abs(a);
			int n = ws(a);
			b = f(a, b, n);
			if (b > 2147483648)
				cout << 0 << endl;
			else
				cout << -b << endl;
		}
	}
}