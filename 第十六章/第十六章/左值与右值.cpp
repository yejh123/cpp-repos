#include<iostream>
using namespace std;
void f1(double& d) {
	cout << "double " << d << endl;
}
void f1(double &&d) {
	cout << "double && " << d << endl;
}
void f1(int& i) {
	cout << "int " << i << endl;
}
void f1(int &&i) {
	cout << "int && " << i << endl;
}
class X {
public:
	X()                         //缺省构造器  
	{
		cout << "默认构造器" << endl;
	}
	X(const X& that) {					//拷贝构造器  
		cout << "拷贝构造器" << endl;
	}
	X(X&& that)                  //移动构造器  
	{
		cout << "移动构造器" << endl;
	}
	X& operator=(const X& that) //拷贝赋值运算符  
	{
		cout << "拷贝赋值运算符" << endl;
	}
	X& operator=(X&& that)      //移动赋值运算符  
	{
		cout << "移动赋值运算符" << endl;
	}
};
int main() {
	/*int i = 1;
	double d = 1.5;
	f1(d);
	f1(i);
	f1(static_cast<double&&>(d));
	f1(static_cast<int&&>(i));*/
	X a;
	X&& b = static_cast<X&&>(a);
	X&& c = std::move(a);
	//static_cast<X&&>(a) 和 std::move(a) 是无名右值引用，是右值  
	//b 和 c 是具名右值引用，是左值  
	X& d = a;
	X& e = b;
	const X& f = c;
	const X& g = X();
	X&& h = X();
	//左值引用d和e只能绑定左值（包括传统左值：变量a以及新型左值：右值引用b）  
	//const左值引用f和g可以绑定左值（右值引用c），也可以绑定右值（临时对象X()）  
	//右值引用b，c和h只能绑定右值（包括新型右值：无名右值引用std::move(a)以及传统右值：临时对象X()） 
}