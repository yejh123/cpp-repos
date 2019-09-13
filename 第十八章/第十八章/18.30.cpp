#include <iostream>
using namespace std;
class Class {

};
class Base :public Class {
public:
	Base() :ival(0) {}
	Base(int i) :ival(i) {}
	Base(const Base& b) :ival(b.ival) {}
//protected:
	int ival;
};
class D1 : virtual public Base {
public :
	D1() :Base(0) {}
	D1(int i) : Base(i) {}
	D1(const D1& d) : Base(d) {}

};
class D2 : virtual public Base {
public:
	D2() :Base(0) {}
	D2(int i) : Base(i) {}
	D2(const D2& d) : Base(d) {}

};
class MI : public D1, public D2 {
public :
	MI() = default;
	MI(int i) :Base(i), D1(i), D2(i) {}
	MI(const MI& m) :D1(m), D2(m) {}

};
class Final : public MI, public Class {
public :
	Final() : MI(), Class() {}
	Final(int i) : Base(i) {}
	Final(const Final &f) : MI(f) {}
};
int main()
{
	Final f(123); 
	cout << "Base::i:" << f.Base::ival << " D1::i:" << f.D1::ival << " D2::i:" << f.D2::ival << " MI::i:"<<f.MI::ival<<" Final::i:" << f.ival << endl;
	MI m(456);
	cout << "Base::i:" << m.Base::ival << " D1::i:" << m.D1::ival << " D2::i:" << m.D2::ival << " Final::i:" << m.ival;

}