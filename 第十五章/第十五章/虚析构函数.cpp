#include<iostream>
using namespace std;
class A {
public:
	~A() {
		cout << "A����������" << endl;
	}
};
class B : public A{
public:
	~B() {
		cout << "B����������" << endl;
	}
};
int main() {
	B b;
	A* x1 = new B();
	delete x1;
}