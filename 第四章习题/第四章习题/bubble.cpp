#include <iostream>
using namespace std;

//ð������
void bubble(int * array, int n)
{
	for (int pass = 0; pass < n - 1; ++pass)
	{
		bool work = 1;
		for (int t = 0; t < n - pass - 1; ++t)
		{
			if (array[t] > array[t + 1])
			{
				swap(array[t], array[t + 1]);
				work = 0;
			}
		}
		if (work == 1)      //work == 1 �����Ѿ�����
			break;
	}
}

int main()
{
	int arr[] = { 10,6,5,2,3,8,7,4,9,1 };
	int n = sizeof(arr) / sizeof(int);
	bubble(arr, n);
	printf("����������Ϊ��\n");
	for (int j = 0; j < n; j++)
		printf("%d ", arr[j]);
	printf("\n");
	return 0;
}