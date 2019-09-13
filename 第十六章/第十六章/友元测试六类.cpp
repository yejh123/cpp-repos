/*
 * cppprimer.cpp
 *
 *  Created on: 2013.11.24
 *      Author: Caroline
 */

 /*eclipse cdt, gcc 4.8.1*/

#include <iostream>
#include <string>

template <typename T> class Pal; //pal����

class C {
	friend class Pal<C>; //"����Cʵ����"��Pal��, ΪC����Ԫ
	template <typename T> friend class Pal2; //Pal2�������ʵ����, ��ΪC����Ԫ
private:
	void print() { std::cout << "class C" << std::endl; }
};

template <typename T>
class C2 {
	friend class Pal<T>; //"��C2����ͬʵ����"��Pal��, ΪC2����Ԫ
	//Pal2�������ʵ����, ��ΪC2����Ԫ,      ע��ģ�����(X)������ͬ(�������飩
	template <typename Q> friend class Pal2;
	friend class Pal3; //��ͨ��Ԫ
	friend T; //C++11 ģ�����Ͳ�����Ԫ
private:
	void print() { std::cout << "class C2" << std::endl; }
};

template <typename T>
class Pal {
	C myC;
	C2<T> myC2; //����ΪT
	//C2<double> myC2; //ʵ������ͬ, �޷�ʹ��
public:
	void printC() {
		std::cout << "this is class Pal : ";
		myC.print();		//C���˽�к���
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
	C2<Pal4> myC2; //ע��Pal4��C2���ģ�����
public:
	void printC2() {
		std::cout << "this is class Pal4 : ";
		myC2.print();
	}
};

int main(void) {

	std::cout << "Hello Mystra!" << std::endl;

	Pal<C> pc; //Pal�����ʵ����ΪC
	pc.printC(); //����ʹ��
	//Pal<int> pci;
	//pci.print(); //����, ������˽�г�Ա

	Pal2<int> pi2; //Pal2���������ʵ����
	pi2.printC();
	pi2.printC2(); //ע��, Pal2�౻ʵ����Ϊ<int>, �ڲ�C2�౻ʵ����Ϊ<double>;

	Pal<int> pi; //����ͬ��ʾ����, ��������C2<T>
	pi.printC2();

	Pal3 p3;
	p3.printC2();

	Pal4 p4;
	p4.printC2();

	return 0;
}