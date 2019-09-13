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
/* vs2017 输出为下
Sub->Base
I'm Sub
I'm Base
<sub->base> sub2base val is: 00B9E080   // 注:这个地址是系统分配的,每次不一定一样

Base->Sub
I'm Base
<base->sub> base2sub val is: 00000000   // VS2017的C++编译器,对此类错误的转换赋值为nullptr


对于从子类到基类的指针转换 ,dynamic_cast 成功转换,没有什么运行异常,且达到预期结果
而从基类到子类的转换 , dynamic_cast 在转换时也没有报错,但是输出给 base2sub 是一个 nullptr ,说明dynami_cast 在程序运行时对类型转换对“运行期类型信息”（Runtime type information，RTTI）进行了检查.
这个检查主要来自虚函数(virtual function) 在C++的面对对象思想中，虚函数起到了很关键的作用，当一个类中拥有至少一个虚函数，那么编译器就会构建出一个虚函数表(virtual method table)来指示这些函数的地址，假如继承该类的子类定义并实现了一个同名并具有同样函数签名（function siguature）的方法重写了基类中的方法，那么虚函数表会将该函数指向新的地址。此时多态性就体现出来了：当我们将基类的指针或引用指向子类的对象的时候，调用方法时，就会顺着虚函数表找到对应子类的方法而非基类的方法。因此注意下代码中 Base 和 Sub 都有声明定义的一个虚函数 ” i_am_virtual_foo” ,我这份代码的 Base 和 Sub 使用 dynami_cast 转换时检查的运行期类型信息,可以说就是这个虚函数
---------------------
作者：ydar95
来源：CSDN
原文：https://blog.csdn.net/ydar95/article/details/69822540
版权声明：本文为博主原创文章，转载请附上博文链接！
*/