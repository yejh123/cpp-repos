#include <iostream>
using namespace std;
template<typename T> class B;
//template <typename T> class A {
//public:
//	int getInt(B<T> b) {
//		return b.i;
//	}
//};
template<typename T> void fun(B<T> b) {
	cout << "fun: B.i ="<<b.i << endl;
}
template<typename T> class B {
//	friend class A<T>;          //ÿ��Bʵ��������Ȩ����������ͬ����ʵ������A
	template<typename T> friend void fun(B<T> b);
	int i = 42;
};
int main() {
	//A<double> ad;
	B<int> bd;
	fun(bd);
}