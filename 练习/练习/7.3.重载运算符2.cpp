/*
设向量X=(x1,x2,…,xn)，向量Y=(y1,y2,…,yn)，它们之间的加、减和乘法分别定义为：
X+Y=(x1+y1,x2+y2,…,xn+yn) X-Y=(x1-y1,x2-y2,…,xn-yn) X*Y=x1*y1+x2*y2+….+xn*yn 编写程序定义向量类Vector，
重载运算符“+”、“-”、“*”，实现向量之间的加、减、乘运算；所给定的向量各分量均为整数，且其绝对值小于1000。

输入为若干组数据，每组数据用4行表示。第1行为1个字符（+、-、*中的一个），表示所要做的向量运算，第2行为一个小于100的正整数，表示向量的长度，
第3行和第4行均为n个整数，各整数间用空格分隔，第3行和第4行表示两个向量。

输出为若干组数据，每组数据用1行表示。若所执行的向量运算为+或-，则输出长度为n的向量，向量的各分量之间用空格分隔（注意最后一个分量后不接空格）；
若所执行的向量运算为*，则输出一个整数，即运算结果。

KeyWord(s) that Must be Used
operator
样例输入
+
3
1 2 3
4 5 6
*
2
1 2
3 4
样例输出
5 7 9
11
*/
#include <iostream>
using namespace std;
class Vector {
public:
	int size;
	int *a;
	int foot;
	friend ostream& operator<<(ostream& os, const Vector& v);
	Vector(int n) :size(n), a(new int[n]),foot(0) {}
	void add(int i) {
		a[foot++] = i;
	}
	Vector operator+(const Vector& v) {
		Vector res(v.size);
		for (int i = 0; i < v.size; ++i) {
			res.add(this->a[i] + v.a[i]);
		}
		return res;
	}
	Vector operator-(const Vector& v) {
		Vector res(v.size);
		for (int i = 0; i < v.size; ++i) {
			res.add(this->a[i] - v.a[i]);
		}
		return res;
	}
	int operator*(const Vector& v) {
		int res = 0;
		for (int i = 0; i < v.size; ++i) {
			res += this->a[i] * v.a[i];
		}
		return res;
	}
};
ostream& operator<<(ostream& os,const Vector& v) {
		for (int i = 0; i < v.size - 1; ++i) {
			os << v.a[i] << " ";
		}
		os << v.a[v.size - 1];
		return os;
	}
int main() {
	char c;
	while (cin >> c) {
		int n;
		cin >> n;
		Vector v1(n), v2(n);
		for (int i = 0; i < n; ++i) {
			int t;
			cin >> t;
			v1.add(t);
		}
		for (int i = 0; i < n; ++i) {
			int t;
			cin >> t;
			v2.add(t);
		}
		if (c == '+') {
			cout << v1 + v2 << endl;
		}
		else if (c == '-') {
			cout << v1 - v2 << endl;
		}
		else if (c == '*') {
			cout << v1 * v2 << endl;
		}
	}
}