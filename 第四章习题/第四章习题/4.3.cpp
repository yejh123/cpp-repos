#include <iostream>
using namespace std;
int main()
{
	int m, n;
	while (cin >> m)
	{
		int a[100];
		int i;
		for (int t = 0; t < m &&cin >> i; ++t)
		{
			a[t] = i;
		}
		cin >> n;
		for (int t = m; t < m + n &&cin>>i; ++t)
		{
			a[t] = i;
		}
		//≈≈–Ú
		for (int pass = 0; pass < m + n - 1; ++pass)
		{
			bool work = 1;
			for (int travel = 0; travel < m + n - pass - 1; ++travel)
			{
				if (a[travel] > a[travel + 1])
				{
					swap(a[travel], a[travel + 1]);
					work = 0;
				}
			}
			if (work)
				break;
		}
		cout << m + n << endl;
		for (int t = 0; t != m + n -1; ++t)
		{
			cout << a[t] << " ";
		}
		cout << a[m + n - 1] << endl;
	}
}