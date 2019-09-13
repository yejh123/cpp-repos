#include<iostream>
using namespace std;
struct A {
	double d;
	A(double d = 0.0) :d(d) { };
	operator double() {
		return d;
	};
	operator float() {
		return d;
	}
	
};
struct B {
	int i = 0;
	B(int i = 0 ):i(i) { }
	operator int() { return i; }
};
int main()
{
	B b(65.5);
	double i1 = b + 3.14;
	cout << i1 << endl;
}