#include <iostream>
using namespace std;
int get_first_num(int t1)
{
	int i = 1;
	for (int t = 1; t <= t1; ++t)
	{
		i += t ;
	}
	return i;
}
int main()
{
	int N, t1 , t2;
	while (cin >> N)
	{
		t1 = 0;
		int i[100][100];
		for (; ; ++t1)
		{
			
			t2 = 1;
			if (get_first_num(t1) <= N)
			{
				i[t1][0] = get_first_num(t1);
				
					for (int n = 2; ; ++n )
					{
						if (i[t1][t2 - 1] + n + t1 <= N)
						{
							i[t1][t2] = i[t1][t2 - 1] + n + t1;
						}
						else
						{
							--t2;
							for (int i2 = 0; i2 < t2; ++i2)
							{
								cout << i[t1][i2] << " ";
							}
							cout << i[t1][t2];
							cout << endl;
							break;
						}
						++t2;
					}
				
			}
			else
			{
				
				break;
			}
		}
		
	}
}