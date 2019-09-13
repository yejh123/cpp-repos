#include<stdio.h>
void InsertSort(int  *a, int n) {
	int tmp = 0;
	for (int i = 1; i < n; i++) {
		int j = i - 1;
		if (a[i] < a[j]) {
			tmp = a[i];
			a[i] = a[j];
			while (tmp < a[j - 1]) {
				a[j] = a[j - 1];
				j--;
			}
			a[j] = tmp;
		}
	}
}
int main() {
	int a[] = { 11,7,9,22,10,18,4,43,5,1,32 };
	int n = sizeof(a) / sizeof(int);
	InsertSort(a, n);
	printf("排序好的数组为：");
	for (int i = 0; i < n; i++) {
		printf(" %d", a[i]);
	}
	printf("\n");
	return 0;
}