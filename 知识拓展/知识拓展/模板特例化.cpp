/*
当函数模板的形参是引用时，无法将数组转化为指针！这是与普通函数形参最难以区分的不同
在任何情况下，都无法将指针转化为数组的引用！
*/
#include <iostream>
#include <string>
using namespace std;

//传指针
void fun1(char (&c)[20]) {
	cout << "fun1 " << typeid(c).name() << endl;

	cout << c << endl;
}

//传数组引用
void fun2(char c[20]) {
	cout << "fun2 " << typeid(c).name() << endl;
	cout << c << endl;

}

void fun3(const char* const & c) {
	cout << "fun3 " << typeid(c).name() << endl;
	cout << c << endl;
}

template<typename T> int compare(const T& t1, const T& t2) {
	cout << "T类型: " << typeid(T).name() << "\t" << "t1类型: " << typeid(t1).name() << endl;
	cout << "t1: " << t1 << "\tt2: " << t2 << endl;
	if (t1 < t2) {
		return -1;
	}
	else if (t1 > t2) {
		return 1;
	}
	else {
		return 0;
	}
}

template<size_t N, size_t M> int compare(const char(&c1)[N], const char(&c2)[M]) {
	
	cout << "c1类型: " << typeid(c1).name() << endl;
	return strcmp(c1, c2);
}

template<> int compare(const char* const &c1, const char* const &c2) {
	cout << "模板特例化" << endl;
	cout << "c1类型: " << typeid(c1).name() << endl;
	return strcmp(c1, c2);
}
int main() {
	char p1[20] = "dsajuio";
	char p2[20] = "dsajuio";
	cout << (void*)p1 << "\t" << (void*)p2 << endl;		//p1和p2地址不同！
	cout << compare(p1, p2) << endl;		//两个模板函数都可调用，但优先调用int compare(const char (&c1)[N], const char (&c2)[M])，传入数组引用
	cout << endl;

	int a[10], b[10];
	cout << compare(a, b) << endl;			//调用template<typename T> int compare(const T& t1, const T& t2)，比较地址值
											//由于两数组大小恰好相等，故传入数组引用，T类型为int [10], 形参类型为int const [10]
	cout << endl;


	const char* p11 = "his", *p22 = "abc";
	cout << compare(p11, p22) << endl;		//传入字符指针，由于无法将一个指针转换为一个数组的引用，所以只能调用template<typename T> int compare(const T& t1, const T& t2)
	cout << endl;

	cout << compare("hi", "his") << endl;	//传入数组引用，调用int compare(const char (&c1)[N], const char (&c2)[M]
											//无法调用template<typename T> int compare(const T& t1, const T& t2)，因为形参是一个引用，数组不会转化为指针！！！
	cout << endl;

	cout << compare("hi", "hi") << endl;	//两个模板函数都可调用，但优先调用int compare(const char (&c1)[N], const char (&c2)[M])

	fun3(p1);
	
}