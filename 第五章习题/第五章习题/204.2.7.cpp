#include <iostream>
using namespace std;
struct data1
{
	char name[12];
	double score;
};
double searchMax(data1 *a, int n);

int main()
{
	data1 stu[] = { "李小平",90,"何文章",66,"刘大安",87,"汪立新",93,"罗建国",78,
			 "陆丰收",81,"杨勇",85,"吴一兵",55,"伍晓笑",68,"张虹虹",93 };
	double max;
	int n = sizeof(stu) / sizeof(data1);
	max = searchMax(stu, n);
	for (int i = 0; i < n; i++)        //使用for遍历整个数组以输出可能存在的多个最大值
		if (stu[i].score == max)
			cout << stu[i].name << '\t' << stu[i].score << endl;
}

double searchMax(data1 *a, int n)
{
	int i;
	double max = a[0].score;
	for (i = 1; i < n; i++)
		if (a[i].score > max) max = a[i].score;
	return max;
}