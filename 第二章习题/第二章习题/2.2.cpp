//输入一个小于1000的正整数，判断该整数是否同时满足用3除余2，用5除余3和用7除余2，若满足则输出1，否则输出0。
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