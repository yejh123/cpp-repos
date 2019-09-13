#include <iostream>
using namespace std;
class A {
public:
	template<typename T> void print() {
		cout << "普通类中的成员模板函数" << endl;
	}
};
template<typename T> void f(const T *a, const T* b) {
	cout << "a = " << a << ", b = " << b << endl;
//	a++, b++;
	cout << "a = " << a << ", b = " << b << endl;
}
void f1(int &&i) {
	cout << i << endl;
}
int main() {
	A a;
	a.print<int>();
	int x = 1, y = 2, z = 3;
	const int ci = 1;
	int *p1 = &x;
	const int *cp1 = &x, *cp2 = &y;
	f(p1, cp1);
	f1(x);
}