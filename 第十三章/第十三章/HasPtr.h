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
	//���캯��
	HasPtr(const string &s=  "") :ps(new string(s)), i(0) {}
	//�������캯��
	HasPtr(const HasPtr &h) {
		ps = new string(*h.ps);
		i = h.i;
	}
	//������ֵ�����
//	HasPtr & operator= (HasPtr hp);
	HasPtr & operator= ( HasPtr hp);
	HasPtr &operator= (HasPtr &&);
	//��������
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
	cout << "���������������" << endl;
	swap(*this, hp);
	return *this;
	
}
HasPtr &HasPtr::operator= (HasPtr &&hp) {
	cout << "�ƶ���ֵ�����" << endl;
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
