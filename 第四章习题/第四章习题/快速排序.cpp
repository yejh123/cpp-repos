//���ʱ�临�Ӷȣ�ÿ��ѡȡ�Ļ�׼Ԫ�ض�Ϊ��󣨻���СԪ�أ�����ÿ��ֻ������һ����������Ҫ����n - 1�λ��ֲ��ܽ����ݹ飬�ʸ��Ӷ�ΪO(n ^ 2)��
//����ʱ�临�Ӷȣ�ÿ��ѡȡ�Ļ�׼Ԫ�ض�����λ����ÿ�ζ����ֳ�������������Ҫ����logn�εݹ飬��ʱ�临�Ӷ�ΪO(nlogn)��
//ƽ��ʱ�临�Ӷȣ�O(nlogn)���ȶ��ԣ����ȶ��ġ������ռ䣺O(nlogn)��
//������Ԫ�ػ�������ʱ����������û���κ����ƣ������˻�Ϊð�����򣬿���ѡȡ��׼Ԫ��ʱѡȡ�м�ֵ�����Ż���

#include <iostream>
using namespace std;
int partition(int * array, int left, int right)          //���֣�������
{
	int travel = left;           //������������
	int small = travel - 1;      //����ָ��С��key��λ��
	int key = array[right];      //keyΪ��׼Ԫ�أ��ֻ��Ľ磩
	for (; travel < right; ++travel)
	{
		if (array[travel] < key)
		{
			swap(array[travel], array[++small]);
		}
	}
	//�ѻ�׼Ԫ�طŵ��м䣨���ϸ��м䣩
	swap(array[right], array[++small]);
	//���������м�λ��
	return small;
}
void quickSort(int *array, int left, int right)          //��������
{
	if (left >= right)                                   //���ֺ�������СΪ1ʱreturn
		return;
	int mid = partition(array, left, right);             //mid�Ƿ���Ľ�
	quickSort(array, left, mid - 1);                     //������С������ݹ�
	quickSort(array, mid + 1, right);                    //�����ϴ�������ݹ�
}
int main()
{
	int a[] = { 54,62,19,19,38,43,59,189,68,62,4 };
	int n = sizeof(a) / sizeof(int);
	quickSort(a, 0, n - 1);
	for (auto i : a)
	{
		cout << i << " ";
	}
	cout << endl;
}
