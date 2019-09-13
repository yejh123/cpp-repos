/*
������X=(x1,x2,��,xn)������Y=(y1,y2,��,yn)������֮��ļӡ����ͳ˷��ֱ���Ϊ��
X+Y=(x1+y1,x2+y2,��,xn+yn) X-Y=(x1-y1,x2-y2,��,xn-yn) X*Y=x1*y1+x2*y2+��.+xn*yn ��д������������Vector��
�����������+������-������*����ʵ������֮��ļӡ����������㣻��������������������Ϊ�������������ֵС��1000��

����Ϊ���������ݣ�ÿ��������4�б�ʾ����1��Ϊ1���ַ���+��-��*�е�һ��������ʾ��Ҫ�����������㣬��2��Ϊһ��С��100������������ʾ�����ĳ��ȣ�
��3�к͵�4�о�Ϊn�����������������ÿո�ָ�����3�к͵�4�б�ʾ����������

���Ϊ���������ݣ�ÿ��������1�б�ʾ������ִ�е���������Ϊ+��-�����������Ϊn�������������ĸ�����֮���ÿո�ָ���ע�����һ�������󲻽ӿո񣩣�
����ִ�е���������Ϊ*�������һ������������������

KeyWord(s) that Must be Used
operator
��������
+
3
1 2 3
4 5 6
*
2
1 2
3 4
�������
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