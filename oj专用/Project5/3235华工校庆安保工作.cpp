#include<iostream>
#include<algorithm>
#include <functional>
using namespace std;
//���ϸ�Ĵ��루��Ȼ��ȷac��
int main()
{
	int n;
	while (cin >> n)
	{
		for (int t1 = 1; t1 <= n; ++t1)
		{
			int n2;
			cin >> n2;
			int i, i2, i3 = 0;
			int *a = new int[n2];   //a�Ƿɻ��߶ȣ� b��ÿ�����������ĸ߶�
			int *b = new int[n2];   //ʵ���������ٴ���50
			for (int t3 = 0; t3 < n2; b[t3] = 0, ++t3);
			for (i = 0; i < n2; ++i)
			{
				int t;
				cin >> t;
				a[i] = t;
			}
			for (i = 0; i < n2; ++i)
			{
				sort(b, b + n2, greater<int>());
				int t2;
				for ( t2 = 0; b[t2] != 0; ++t2);
				sort(b, b + t2 );
				for (i2 = 0; ; ++i2)
				{
					if (i2 >= n2 - 1 )
					{
						b[n2 -1] = a[i];
						break;
					}
					if (a[i] <= b[i2])
					{
						b[i2] = a[i];
						break;
					}
				}
				
			}
			sort(b, b + n2, greater<int>());
			for (i2 = 0; b[i2] != 0 && i2 < n2; ++i2)
			{
				++i3;
				//cout << b[i2];
			}
			cout << i3 << endl;
		}
	}
}