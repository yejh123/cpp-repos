#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	vector<int> v1, v2;
	int i;
	bool bl = 1;
	cout << "请输入v1的元素" << endl;
	while (cin >> i)
		v1.push_back(i);
	cin.clear();
	cout << "请输入v2的元素" << endl;
	while (cin >> i)
		v2.push_back(i);
	cout << "vector1: ";
	for (auto c : v1)
		cout << c<<" ";
	cout << endl;
	cout << "vector2: ";
	for (auto c : v2)
		cout << c << " ";
	cout << endl;
	cout << v1.size() << endl;
	cout << v2.size() << endl;
	if (v1.size() == v2.size())
	{
		cout << "两vector对象都不是对方的前缀" << endl;
		return 0;
	}
	if (v1.size() < v2.size())
	{
		for( auto a = v1.cbegin(), b= v2.cbegin(); a!= v1.cend();++a,++b){
            if (*a != *b)
			    bl = false;
		}
		if (bl)
			cout << "v1是v2的前缀" << endl;
		else cout << "两vector对象都不是对方的前缀" << endl;
		return 0;

	}
	if (v1.size() > v2.size())
	{
		for (auto a = v1.cbegin(), b = v2.cbegin(); b != v2.cend(); ++a, ++b)
			if (*b != *a)
			{
				bl = false;
			}
		if (bl)
			cout << "v1是v2的前缀" << endl;
		else cout << "两vector对象都不是对方的前缀" << endl;
		return 0;

	}
	
	return 0;
}