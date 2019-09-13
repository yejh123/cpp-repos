#include <iostream>
#include <iomanip>
using namespace std;
class A {
public:
	void fun() {
		print();
	}
private:
	 virtual void print() {
		cout << "A" << endl;
	}
};
class B : public A{
public:
	 virtual void print() {
		cout << "B" << endl;
	}
};
int main()
{
	A * ptr = new B();
	ptr->fun();
}