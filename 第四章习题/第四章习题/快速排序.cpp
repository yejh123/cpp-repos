//最差时间复杂度：每次选取的基准元素都为最大（或最小元素）导致每次只划分了一个分区，需要进行n - 1次划分才能结束递归，故复杂度为O(n ^ 2)；
//最优时间复杂度：每次选取的基准元素都是中位数，每次都划分出两个分区，需要进行logn次递归，故时间复杂度为O(nlogn)；
//平均时间复杂度：O(nlogn)。稳定性：不稳定的。辅助空间：O(nlogn)。
//当数组元素基本有序时，快速排序将没有任何优势，基本退化为冒泡排序，可在选取基准元素时选取中间值进行优化。

#include <iostream>
using namespace std;
int partition(int * array, int left, int right)          //划分：分两组
{
	int travel = left;           //用来遍历数组
	int small = travel - 1;      //用来指向小于key的位置
	int key = array[right];      //key为基准元素（分划的界）
	for (; travel < right; ++travel)
	{
		if (array[travel] < key)
		{
			swap(array[travel], array[++small]);
		}
	}
	//把基准元素放到中间（非严格中间）
	swap(array[right], array[++small]);
	//返回数组中间位置
	return small;
}
void quickSort(int *array, int left, int right)          //快速排序
{
	if (left >= right)                                   //划分后的数组大小为1时return
		return;
	int mid = partition(array, left, right);             //mid是分组的界
	quickSort(array, left, mid - 1);                     //对数较小组排序递归
	quickSort(array, mid + 1, right);                    //对数较大组排序递归
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
