#include <iostream>
#include <algorithm>
using namespace std;
//double max(double, double);    // ����ԭ��
int main()
{
	double a, b, c, m1, m2;
	cout << "input a, b, c :\n";
	cin >> a >> b >> c;
	m1 = max(a, b);            // ��������
	m2 = max(m1, c);
	cout << "Maximum = " << m2 << endl;
}
//double max(double x, double y)    // ��������
//{
//	if (x > y)    return x;
//	else     return y;
//}