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
	data1 stu[] = { "��Сƽ",90,"������",66,"����",87,"������",93,"�޽���",78,
			 "½����",81,"����",85,"��һ��",55,"����Ц",68,"�ź��",93 };
	double max;
	int n = sizeof(stu) / sizeof(data1);
	max = searchMax(stu, n);
	for (int i = 0; i < n; i++)        //ʹ��for��������������������ܴ��ڵĶ�����ֵ
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