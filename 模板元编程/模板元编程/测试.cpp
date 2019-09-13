#include <iostream>
using namespace std;
// Prime number computation by Erwin Unruh
template<int i> struct D { D(void*); operator int(); }; // 构造函数参数为 void* 指针

template<int p, int i> struct is_prime { // 判断 p 是否为素数，即 p 不能整除 2...p-1
	enum { prim = 1.0 };
};


int main() {
	is_prime<1, 2> p;
	cout << p.prim << endl;
}