#pragma once
#include <iostream>
#include <string>
#include <memory>
using namespace std;
struct String {
	friend bool operator==(const String &s1, const String &s2);
	friend bool operator!=(const String &s1, const String &s2);
private:
	static allocator<char> alloc;
	char * elements ;
	char *first_free;
	char *cap ;
	//	void 

public:
	String() = default;
	String(const char* c);
	String(const String &);
	String& operator=(const String &);
	String(String &&) noexcept;
	String &operator=(String && ) noexcept;
	~String();
	void free();
	char *begin() { return elements; }
	void print();
};
allocator<char> String::alloc;
String::String(const char *c) {
	auto p = alloc.allocate(strlen(c));

	auto p2 = uninitialized_copy(c, c + strlen(c), p);    //uninitialized_copy返回尾后元素的指针
	elements = p;
	first_free = cap = p2;
	cout << "C风格字符串初始化" << endl;
}
String::String(const String &s) {
	auto p = alloc.allocate(s.cap - s.elements); 
	char * p3 = uninitialized_copy(s.elements,s.first_free, p);
	elements = p;
	first_free = cap = p3;
	cout << "拷贝构造函数" << endl;
}
//移动构造函数
String::String(String &&s) noexcept
{
	elements = std::move(s.elements);
	first_free = std::move(first_free);
	cap = std::move(cap);
	s.elements = s.first_free = s.cap = nullptr;
	cout << "移动构造函数" << endl;
}
String &String::operator=(String &&s) noexcept {
	if (this != &s) {
		free();
		elements = std::move(s.elements);
		first_free = std::move(first_free);
		cap = std::move(cap);
		s.elements = s.first_free = s.cap = nullptr;
		cout << "移动赋值运算符" << endl;
	}
	return *this;
}
void String::free() {
	if (elements) {
		for (auto a = first_free; a != elements;) {
			alloc.destroy(--a);
		}
		elements = first_free = cap = nullptr;
		alloc.deallocate(elements, cap - elements); //重点
	}
}
String&  String::operator=(const String &s) {
	 auto p = alloc.allocate(s.cap - s.elements);
	 auto p2 = uninitialized_copy(s.elements, s.first_free, p);
	 free();
	 elements = p;
	 first_free = p2;
	 cout << "拷贝赋值运算符" << endl;
	 return *this;
}
String::~String() {
	free();
}
void String::print() {
	auto p = elements;
		for (; p != first_free; ++p)
			cout << *p;
		cout << endl;
}
bool operator==(const String &s1, const String &s2) {
	bool bl =1 ;
	//auto i = s1.first_free - s1.elements;
	if (s1.first_free - s1.elements != s2.first_free - s2.elements) {
		bl = 0;
		return bl;
	}
	for (auto p1 = s1.elements , p2 = s2.elements ; p1 != s1.elements; ++p1,++p2) {
		if (*p1 != *p2) {
			bl = 0;
			break;
		}
	}
	return bl;
 }
bool operator!=(const String &s1, const String &s2) {
	return !(s1 == s2);
}
