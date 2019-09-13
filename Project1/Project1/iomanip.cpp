#include <iostream>
#include <algorithm>
using namespace std;
//double max(double, double);    // 函数原型
int main()
{
	double a, b, c, m1, m2;
	cout << "input a, b, c :\n";
	cin >> a >> b >> c;
	m1 = max(a, b);            // 函数调用
	m2 = max(m1, c);
	cout << "Maximum = " << m2 << endl;
}
//double max(double x, double y)    // 函数定义
//{
//	if (x > y)    return x;
//	else     return y;
//}