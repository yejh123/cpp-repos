#include<iostream>
using namespace std;
class A {
public:
	~A() {
		cout << "A的析构函数" << endl;
	}
};
class B : public A{
public:
	~B() {
		cout << "B的析构函数" << endl;
	}
};
int main() {
	B b;
	A* x1 = new B();
	delete x1;
}