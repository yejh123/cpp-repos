/*
������Ԫ��ϵ֮��ģ��������ģ�����Ԫ
����ʵ�֣�ʹ����ģ��������������������������ģ�����Ԫ��ϵ
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
//��ģ��������
template<> class C1<int> {
	template<typename T> friend class C2;
private:
	void print() {
		cout << "class C1 print" << endl;
	}
};

template<typename T> class C2 {

	C1<int> myC1;		//int�������������Ͳ������Ӧ
public:
	void print() {
		myC1.print();
	}
};

int main() {

	C2<int> c2;
	c2.print();
}