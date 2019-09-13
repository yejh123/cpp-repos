#include<iostream>
using namespace std;
int Max3(int i1, int i2, int i3)
{
	int max2 = i1 > i2 ? i1 : i2;
	int max3 = max2 > i3 ? max2 : i3;
	return max3;
}
int MaxSubSum(const int A[], int Left, int Right)
{
	int MaxLeftSum, MaxRightSum;
	int MaxLeftBorderSum, MaxRightBorderSum;
	int LeftBorderSum, RightBorderSum;
	int Center;
	if (Left == Right)
	{
		if (A[Left] > 0)
			return A[Left];
		else
			return 0;
	}
	Center = (Left + Right) / 2;

	//求左半边和右半边的最大子序列
	MaxLeftSum = MaxSubSum(A, Left, Center);
	MaxRightSum = MaxSubSum(A, Center + 1, Right);

	//求包含中间元素的最大子序列
	LeftBorderSum = MaxLeftBorderSum = 0;
	for (int i = Center; i >= Left; --i)
	{
		LeftBorderSum += A[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}
	RightBorderSum = MaxRightBorderSum = 0;
	for (int i = Center + 1; i <= Right; ++i)
	{
		RightBorderSum += A[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}

	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}
int MaxSubsequenceSum(const int A[], int N)
{
	return MaxSubSum(A, 0, N - 1);
}

int main()
{
	int A[8] = { 4, -3, 5, -2, -1, 2, 6, -2 };
	cout << MaxSubsequenceSum(A, 8);
}