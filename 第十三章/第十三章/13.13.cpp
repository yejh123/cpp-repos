#include <iostream>
#include <string>
#include <vector>
using namespace std;
class X
{
private:
	string s;
public:
	X(const string &s):s(s) { cout << "���캯�� X()" << endl; }
	X(const X &x)  { 
		s = x.s;
		cout << "�������캯��" << endl;
	}
	X & operator= (const X &x) { 
		s = x.s;
		cout << "������ֵ�����" << endl; 
	    return *this;
	}
	~X() { cout << "��������" << endl; }

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
	f1(x);         //�������캯�� ��������
	cout << endl;
	f2(x);         //��
	cout << endl;
	auto a = new X(x); //�������캯��
	delete a;          //��������
	cout << endl;
	cout << "����vector";
	//vector<X> v;  //�������캯��*2 ��������
	cout << endl;
	cout << "push_back";
	//v.push_back(x);
	cout << endl;
}                      //������������� *2��