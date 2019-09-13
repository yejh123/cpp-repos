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
		if (a[i] > b[j])             		//��a[i]>b[j]����b[i]д������c
		{
			c[k] = b[j];  k++;  j++;
		}
		else                          	//��a[i]<=b[j]����a[i]д������c
		{
			c[k] = a[i];  k++;  i++;
		}
	}
	while (i < na)
	{
		c[k] = a[i];  i++;  k++;			 //������a��ʣ��Ԫ��д������c
	}
	while (j < nb)
	{
		c[k] = b[j];  k++;  j++;			//������b��ʣ��Ԫ��д������c
	}
}