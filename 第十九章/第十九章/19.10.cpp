#include <iostream>
#include <typeinfo>
using namespace std;
class A {
public:
	virtual ~A() {
	}
};
class B :public A {
public:
	virtual ~B() override {
	}
};
int main() {
	B *b = new B;
	A &ra = *b;
	cout << typeid(&ra).name() << endl;
}