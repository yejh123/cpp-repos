#include<iostream>
using namespace std;

class Base {
public:
	Base() {}
	~Base() {}
	void print() {
		std::cout << "I'm Base" << endl;
	}

	virtual void i_am_virtual_foo() {}
};

class Sub : public Base {
public:
	Sub() {}
	~Sub() {}
	void print() {
		std::cout << "I'm Sub" << endl;
	}

	virtual void i_am_virtual_foo() {}
};
int main() {
	cout << "Sub->Base" << endl;
	Sub * sub = new Sub();
	sub->print();
	Base* sub2base = dynamic_cast<Base*>(sub);
	if (sub2base != nullptr) {
		sub2base->print();
	}
	cout << "<sub->base> sub2base val is: " << sub2base << endl;


	cout << endl << "Base->Sub" << endl;
	Base *base = new Base();
	base->print();
	Sub  *base2sub = dynamic_cast<Sub*>(base);
	if (base2sub != nullptr) {
		base2sub->print();
	}
	cout << "<base->sub> base2sub val is: " << base2sub << endl;

	delete sub;
	delete base;
	return 0;
}
/* vs2017 ���Ϊ��
Sub->Base
I'm Sub
I'm Base
<sub->base> sub2base val is: 00B9E080   // ע:�����ַ��ϵͳ�����,ÿ�β�һ��һ��

Base->Sub
I'm Base
<base->sub> base2sub val is: 00000000   // VS2017��C++������,�Դ�������ת����ֵΪnullptr


���ڴ����ൽ�����ָ��ת�� ,dynamic_cast �ɹ�ת��,û��ʲô�����쳣,�ҴﵽԤ�ڽ��
���ӻ��ൽ�����ת�� , dynamic_cast ��ת��ʱҲû�б���,��������� base2sub ��һ�� nullptr ,˵��dynami_cast �ڳ�������ʱ������ת���ԡ�������������Ϣ����Runtime type information��RTTI�������˼��.
��������Ҫ�����麯��(virtual function) ��C++����Զ���˼���У��麯�����˺ܹؼ������ã���һ������ӵ������һ���麯������ô�������ͻṹ����һ���麯����(virtual method table)��ָʾ��Щ�����ĵ�ַ������̳и�������ඨ�岢ʵ����һ��ͬ��������ͬ������ǩ����function siguature���ķ�����д�˻����еķ�������ô�麯����Ὣ�ú���ָ���µĵ�ַ����ʱ��̬�Ծ����ֳ����ˣ������ǽ������ָ�������ָ������Ķ����ʱ�򣬵��÷���ʱ���ͻ�˳���麯�����ҵ���Ӧ����ķ������ǻ���ķ��������ע���´����� Base �� Sub �������������һ���麯�� �� i_am_virtual_foo�� ,����ݴ���� Base �� Sub ʹ�� dynami_cast ת��ʱ����������������Ϣ,����˵��������麯��
---------------------
���ߣ�ydar95
��Դ��CSDN
ԭ�ģ�https://blog.csdn.net/ydar95/article/details/69822540
��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�
*/