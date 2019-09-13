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
	X()                         //ȱʡ������  
	{
		cout << "Ĭ�Ϲ�����" << endl;
	}
	X(const X& that) {					//����������  
		cout << "����������" << endl;
	}
	X(X&& that)                  //�ƶ�������  
	{
		cout << "�ƶ�������" << endl;
	}
	X& operator=(const X& that) //������ֵ�����  
	{
		cout << "������ֵ�����" << endl;
	}
	X& operator=(X&& that)      //�ƶ���ֵ�����  
	{
		cout << "�ƶ���ֵ�����" << endl;
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
	//static_cast<X&&>(a) �� std::move(a) ��������ֵ���ã�����ֵ  
	//b �� c �Ǿ�����ֵ���ã�����ֵ  
	X& d = a;
	X& e = b;
	const X& f = c;
	const X& g = X();
	X&& h = X();
	//��ֵ����d��eֻ�ܰ���ֵ��������ͳ��ֵ������a�Լ�������ֵ����ֵ����b��  
	//const��ֵ����f��g���԰���ֵ����ֵ����c����Ҳ���԰���ֵ����ʱ����X()��  
	//��ֵ����b��c��hֻ�ܰ���ֵ������������ֵ��������ֵ����std::move(a)�Լ���ͳ��ֵ����ʱ����X()�� 
}