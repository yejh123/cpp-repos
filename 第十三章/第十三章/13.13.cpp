#include <iostream>
#include <string>
#include <vector>
using namespace std;
class X
{
private:
	string s;
public:
	X(const string &s):s(s) { cout << "构造函数 X()" << endl; }
	X(const X &x)  { 
		s = x.s;
		cout << "拷贝构造函数" << endl;
	}
	X & operator= (const X &x) { 
		s = x.s;
		cout << "拷贝赋值运算符" << endl; 
	    return *this;
	}
	~X() { cout << "析构函数" << endl; }

};
void f1(X x)
{

}
void f2(X &x)
{

}
int main()
{
	X x("sd");
	f1(x);         //拷贝构造函数 析构函数
	cout << endl;
	f2(x);         //无
	cout << endl;
	auto a = new X(x); //拷贝构造函数
	delete a;          //析构函数
	cout << endl;
	cout << "创建vector";
	//vector<X> v;  //拷贝构造函数*2 析构函数
	cout << endl;
	cout << "push_back";
	//v.push_back(x);
	cout << endl;
}                      //析构函数（多个 *2）