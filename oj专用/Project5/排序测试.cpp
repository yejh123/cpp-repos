#include "bubble.h"
int main() 
{
	int arr[] = { 10,6,5,2,3,8,7,4,9,1 };
	int n = sizeof(arr) / sizeof(int);
	bubble(arr, n);
	printf("排序后的数组为：\n");
	for (int j = 0; j < n; j++)
		printf("%d ", arr[j]);
	printf("\n");
	return 0;
}