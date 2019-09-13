/*
 * cppprimer.cpp
 *
 *  Created on: 2013.11.24
 *      Author: Caroline
 */

 /*eclipse cdt, gcc 4.8.1*/

#include <iostream>
#include <string>

template <typename T> class Pal; //pal朋友

class C {
	friend class Pal<C>; //"以类C实例化"的Pal类, 为C的友元
	template <typename T> friend class Pal2; //Pal2类的所有实例化, 都为C的友元
private:
	void print() { std::cout << "class C" << std::endl; }
};

template <typename T>
class C2 {
	friend class Pal<T>; //"与C2类相同实例化"的Pal类, 为C2的友元
	//Pal2类的所有实例化, 都为C2的友元,      注意模板参数(X)不能相同(？有异议）
	template <typename Q> friend class Pal2;
	friend class Pal3; //普通友元
	friend T; //C++11 模板类型参数友元
private:
	void print() { std::cout << "class C2" << std::endl; }
};

template <typename T>
class Pal {
	C myC;
	C2<T> myC2; //必须为T
	//C2<double> myC2; //实例化不同, 无法使用
public:
	void printC() {
		std::cout << "this is class Pal : ";
		myC.print();		//C类的私有函数
	}
	void printC2() {
		std::cout << "this is class Pal : ";
		myC2.print();
	}
};

template <typename T>
class Pal2 {
	C myC;
	C2<float> myC2;
public:
	void printC() {
		std::cout << "this is class Pal2 : ";
		myC.print();
	}
	void printC2() {
		std::cout << "this is class Pal2 : ";
		myC2.print();
	}
};

class Pal3 {
	C2<double> myC2;
public:
	void printC2() {
		std::cout << "this is class Pal3 : ";
		myC2.print();
	}
};

class Pal4 {
	C2<Pal4> myC2; //注意Pal4是C2类的模板参数
public:
	void printC2() {
		std::cout << "this is class Pal4 : ";
		myC2.print();
	}
};

int main(void) {

	std::cout << "Hello Mystra!" << std::endl;

	Pal<C> pc; //Pal类必须实例化为C
	pc.printC(); //可以使用
	//Pal<int> pci;
	//pci.print(); //报错, 访问了私有成员

	Pal2<int> pi2; //Pal2类可以随意实例化
	pi2.printC();
	pi2.printC2(); //注意, Pal2类被实例化为<int>, 内部C2类被实例化为<double>;

	Pal<int> pi; //有相同的示例化, 在类声明C2<T>
	pi.printC2();

	Pal3 p3;
	p3.printC2();

	Pal4 p4;
	p4.printC2();

	return 0;
}