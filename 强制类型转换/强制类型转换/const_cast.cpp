/*
1、常量指针被转化成非常量的指针，并且仍然指向原来的对象；
2、常量引用被转换成非常量的引用，并且仍然指向原来的对象；
3、const_cast一般用于修改指针。如const char *p形式。
*/
#include<iostream>
#include <string>
using namespace std;
void test1() {
	string str1 = "abc";			//声明为非常量类型
	const string* p1 = &str1;		//声明为const指针
	string* p2 = const_cast<string*>(p1);		//使用去const 指针
	cout << str1 << "\t" << *p1 << "\t" << *p2 << endl;		//合法行为
	*p2 = "efg";
	cout << str1 << "\t" << *p1 << "\t" << *p2 << endl;

	/* 在 vs2017 下 输出为
		abc abc abc	
		efg efg efg
	*/
}
void test2() {
	const int c_val = 233;  //声明为常量类型
	int &use_val = const_cast<int&>(c_val); //使用去const 引用
	int *ptr_val = const_cast<int*>(&c_val);//使用去const 指针

	use_val = 666;  //未定义行为
	std::cout << c_val << "\t" << use_val << "\t" << *ptr_val << std::endl;
	*ptr_val = 110; //未定义行为
	std::cout << c_val << "\t" << use_val << "\t" << *ptr_val << std::endl;
	std::cout << &c_val << "\t" << &use_val << "\t" << ptr_val << std::endl;

	/* 在 vs2017 下 输出为
		233 666 666
		233 110 110
	*/
}
int main() {
	test1();
	test2();
}