#include <iostream>
using namespace std;
// Prime number computation by Erwin Unruh
template<int i> struct D { D(void*); operator int(); }; // ���캯������Ϊ void* ָ��

template<int p, int i> struct is_prime { // �ж� p �Ƿ�Ϊ�������� p �������� 2...p-1
	enum { prim = 1.0 };
};


int main() {
	is_prime<1, 2> p;
	cout << p.prim << endl;
}