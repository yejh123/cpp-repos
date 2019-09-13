#include <iostream>
#include <set>
using namespace std;
int main()
{
	typedef multiset<int>::iterator iterator;
	while (1)
	{
		multiset<int> si;
		int num1, num2;
		cin >> num1;
		int i;
		for (int t = 1; t <= num1 && cin >> i; ++t)
		{
			si.insert(i);
		}
		cin >> num2;
		for (int t = 1; t <= num2 && cin >> i; ++t)
		{
			si.insert(i);
		}
		cout << num1 + num2 << endl;
		int count = 1;
		for (iterator it = si.begin(); it != si.end(); ++it, ++count)
		{
			cout << *it;
			if (count != num1 + num2)
				cout << " ";
		}
		cout << endl;
	}
}