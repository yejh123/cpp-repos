#include <iostream>
#include <string>
using namespace std;
class A
{
public:
	string name;
	A(const string &s):name(s) { }
	A() = default;A(A &&) = default;
	A& operator=(const A&) = default;
	A& operator=(A &&) = default;
	virtual ~A() { }
};
class B : public A {
public:
	B(const string &s):A(s) { }
	//B(B &&) = default;
	B(const B&b) {
		name = b.name;
		cout << "¿½±´¹¹Ôìº¯Êý" << endl;
	}
};
int main(void)
{
	A a("jfiqh");
	B b1("fhqo");
	cout << endl;
	B b2(std::move(b1));
	std::cout <<"b2.name:"<< b2.name <<"\n"<<"b1.name:"<<b1.name<< std::endl;

	return 0;
}

