#include<iostream>
#include<string>
#include <typeinfo>
using namespace std;
class Base {
public:
	virtual void print() {
		cout << "Base" << endl;
	}
};
class Child : public Base {
public:
	/*virtual void print() override{
		cout << "Child" << endl;
	}*/
	void print2() {
		cout << "Child" << endl;

	}
};
int main() {
	Base* b = new Child;
	Child* c = new Child;
	string str;
	cout << typeid(str).name() << endl;
	cout << typeid(*b).name() << endl;
	cout << typeid(*c).name() << endl;
	cout << (typeid(*b) == typeid(*c)) << endl;
	Child* c2;
	if (c2 = dynamic_cast<Child*>(b)) {
		c2->print2();
	}
	try {
		Child& c3 = dynamic_cast<Child&>(*b);
		c3.print2();
		c3.print();
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
}