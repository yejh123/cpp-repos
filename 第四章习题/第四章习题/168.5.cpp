#include<iostream>
using namespace std;
void merge(const int a[], int na, const int b[], int nb, int c[], int nc);
int main()
{
	int a[4] = { 1, 2, 5, 7 };
	int b[8] = { 3, 4, 8, 8, 9, 10, 11, 12 };
	int c[12];
	int i;
	merge(a, 4, b, 8, c, 12);
	for (i = 0; i < 12; i++)
		cout << c[i] << "   ";
	cout << endl;
}
void merge(const int a[], int na, const int b[], int nb, int c[], int nc)
{
	int i, j, k;
	i = j = k = 0;
	while (i < na && j < nb)
	{
		if (a[i] > b[j])             		//当a[i]>b[j]，把b[i]写入数组c
		{
			c[k] = b[j];  k++;  j++;
		}
		else                          	//当a[i]<=b[j]，把a[i]写入数组c
		{
			c[k] = a[i];  k++;  i++;
		}
	}
	while (i < na)
	{
		c[k] = a[i];  i++;  k++;			 //把数组a的剩余元素写入数组c
	}
	while (j < nb)
	{
		c[k] = b[j];  k++;  j++;			//把数组b的剩余元素写入数组c
	}
}