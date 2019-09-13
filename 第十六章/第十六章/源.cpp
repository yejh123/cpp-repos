/*
声明友元关系之：模板类是类模板的友元
具体实现：使用类模板特例化，并在类中声明对类模板的友元关系
*/
#include <iostream>
using namespace std;
template<typename T> class C2;

template<typename T> class C1 {
private:
	void print() {
		cout << "class C1 print" << endl;
	}
};
//类模板特例化
template<> class C1<int> {
	template<typename T> friend class C2;
private:
	void print() {
		cout << "class C1 print" << endl;
	}
};

template<typename T> class C2 {

	C1<int> myC1;		//int与特例化的类型参数相对应
public:
	void print() {
		myC1.print();
	}
};

int main() {

	C2<int> c2;
	c2.print();
}