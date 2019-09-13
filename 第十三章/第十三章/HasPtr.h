#include <iostream>
#include <string>
using namespace std;
//#include
using namespace std;
class HasPtr {
	friend void swap(HasPtr &h1, HasPtr &h2);
private:
	string *ps = new string ();
	int i;
public:
	//构造函数
	HasPtr(const string &s=  "") :ps(new string(s)), i(0) {}
	//拷贝构造函数
	HasPtr(const HasPtr &h) {
		ps = new string(*h.ps);
		i = h.i;
	}
	//拷贝赋值运算符
//	HasPtr & operator= (HasPtr hp);
	HasPtr & operator= ( HasPtr hp);
	HasPtr &operator= (HasPtr &&);
	//析构函数
	~HasPtr()
	{
		delete ps;
	}
	void print() {
		cout << *ps << " " << i << endl;
	}
};
HasPtr f(HasPtr hp) {
	HasPtr ret = hp;
	return ret;
}
/*HasPtr & HasPtr::operator= ( HasPtr  hp)
{
	swap(*this, hp);
	return *this;
}
*/
HasPtr & HasPtr::operator= ( HasPtr hp) {
	cout << "拷贝并交换运算符" << endl;
	swap(*this, hp);
	return *this;
	
}
HasPtr &HasPtr::operator= (HasPtr &&hp) {
	cout << "移动赋值运算符" << endl;
	if (this != &hp) {
		delete ps;
		ps = hp.ps;
		i = hp.i;
		hp.ps = nullptr;
		hp.i = 0;
	}
	return *this;
}
void swap(HasPtr &h1, HasPtr &h2) {
	swap(h1.ps, h2.ps);
	swap(h1.i, h2.i);
//	cout << "sawp" << endl;
}
