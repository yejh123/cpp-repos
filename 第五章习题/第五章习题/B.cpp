#include<iostream>
#include<string>
using namespace std;
struct student
{
	string	name;
	int s;
};
int main()
{
	int n;
	while (cin >> n)
	{
		student *a = new student[n];
		int max = 0;
		int index;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i].name >> a[i].s;
			if (a[i].s > max)
			{
				max = a[i].s;
				index = i;
			}
		}
		cout << a[index].name << endl;
	}
	
}