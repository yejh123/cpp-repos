#include <iostream>
using namespace std;
int main()
{
	int n;
	int array[20][20];
	while (cin >> n)
	{
		int sum = 0;
		for (int row = 0; row < n; ++row)
		{

			array[row][0] = row + 1;
			int line = 1;
			if (row)
				sum += array[row][0];
			for (; line < n; ++line)
			{
				array[row][line] = array[row][0] - line < 1 ? 1 : array[row][line-1] - 1;
				if (row > line)
				{
					sum += array[row][line];
				}
			}
			for (int t = 0; t < line - 1; ++t)
			{
				cout << array[row][t] << " ";
			}
			cout << array[row][--line] << endl;
			
		 }
		cout << sum << endl;
	}
}