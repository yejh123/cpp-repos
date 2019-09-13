#include <iostream>
using namespace std;
template< typename T, int n>
int f(const T (&t) [n],T item)
{
	int low = 0, high = n - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (t[mid] == item)
		{
			return mid;
		}
		if (t[mid] < item)
		{
			low = mid + 1;
		}
		if (t[mid] > item)
		{
			high = mid - 1;
		}
		
	}
	return -1;
}
int main()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << f(a, 11);
}
