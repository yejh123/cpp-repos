#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	while (cin >> a >> b >> c)
	{
		if (a > b)
			swap(a, b);
		if (a > c)
			swap(a, c);
		if (b > c)
			swap(b, c);
		cout << a << " " << b << " " << c << endl;
	}
}