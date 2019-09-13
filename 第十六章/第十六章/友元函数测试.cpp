#include <iostream>
/*
f1 ��ͨ����
f2 ����ģ��
C ��ģ��*/
using namespace std;
template<typename T> class C;
template<typename T> void f2(const C<T>& t);

template<typename T> class C {
	friend void f1();
	template<typename T> friend void f2(const C<T>& t);
	//friend void f2<T>(const C<T>& t);
private:
	void print() {
		cout << "This is class C ";
	}
};

void f1() {
	C<double> ci;
	ci.print();
	cout << "f1()" << endl;
}

template<typename T> void f2(const C<T>& t) {
	C<double> ci;
	ci.print();
	cout << "f2()" << endl;
}

int main() {
	f1();
	C<int> cd;
	f2(cd);  //f2<double>��C<int>����Ԫ
}