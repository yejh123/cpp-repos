//����һ��С��1000�����������жϸ������Ƿ�ͬʱ������3����2����5����3����7����2�������������1���������0��
#include<iostream>
using namespace std;
int main()
{
	int i;
	while (cin >> i)
	{
		bool bl1 = (3 * (i / 3) + 2 == i), bl2 = (5 * (i / 5) + 3 == i), bl3 = (7 * (i / 7) + 2);
		cout << (bl1 && bl2 && bl3) << endl;
	}
}