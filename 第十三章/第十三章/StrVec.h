#pragma once
#ifndef STRVEC_H
#define STRVEC_H
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <initializer_list>

struct StrVec {
private:
	static std::allocator<std::string> alloc;
	std::string * elements = nullptr;
	std::string *first_free = nullptr;
	std::string *cap = nullptr;
	//工具函数
	//void reallocate();
	void check();
public:
	//构造函数
	StrVec() = default;
	StrVec(const std::initializer_list<std::string> &ils);
	//拷贝构造函数
	StrVec(const StrVec &);
	//拷贝赋值运算符
	StrVec &operator= (const StrVec &);
	//析构函数
	~StrVec();
	//接口函数
	size_t size() { return first_free - elements; }
	size_t capacity() { return cap - elements; }
	void reserve(int t);
	void resize(size_t i);
	std::string *begin() { return elements; }
	std::string *end() { return first_free; }
	std::pair<std::string*, std::string* > n_copy(const std::string *beg, const std::string *end);
	void push_back(const std::string &);
	void free();
	void reallocate();

};
 std::allocator<std::string> StrVec::alloc;       //类外定义static对象
//分配内存,拷贝对象
std::pair<std::string*, std::string* > StrVec::n_copy(const std::string *beg, const std::string *end) {
	auto data = alloc.allocate(end - beg);
	return  { data,uninitialized_copy(beg,end,data) };    //uninitialized_copy返回尾后元素的指针

}
void StrVec::free() {
	if (elements) {
		for (auto a = first_free; a != elements;) {
			alloc.destroy(--a);
		}
		elements = first_free = cap = nullptr;
		alloc.deallocate(elements, cap - elements); //重点
	}

}
/*
void StrVec::free() {
	if (elements)
		for_each(elements,first_free,[]( std::string &s){alloc.destroy(&s);})
}

*/
StrVec::StrVec(const std::initializer_list<std::string> &ils) {
	auto p = n_copy(ils.begin(), ils.end());
	elements = p.first;
	cap = first_free = p.second;
}
StrVec::StrVec(const StrVec &s) {
	auto p = n_copy(s.elements, s.first_free);
	elements = p.first;
	cap = first_free = p.second;

}
StrVec &StrVec::operator=(const StrVec &s) {
	free();
	auto p = n_copy(s.elements, s.first_free);
	elements = p.first;
	cap = first_free = p.second;
	return *this;
}
StrVec::~StrVec() {
	free();
}
//重分配,移动对象
void StrVec::reallocate() {
	auto newcapacity = size() ? 2 * size() : 1;
	auto sp = alloc.allocate(newcapacity);
	auto new_ele = sp, old_ele = elements;
	for (size_t i = 0; i != size(); ++i) {
		alloc.construct(new_ele++, std::move(*old_ele++));// *sp++ = std::move(*old_ele++);
	}
	free();      //销毁原StrVec保存的内存
	elements = sp;
	first_free = new_ele;
	cap = elements + newcapacity;
}
void StrVec::check() {
	if (size() == capacity()) {
		reallocate();
	}
}
void StrVec::push_back(const std::string &s) {
	check();
	alloc.construct(first_free++, s);
}
void StrVec::reserve(int t) {
	while (t > cap - elements)
	{
		reallocate();
	}
}
void StrVec::resize(size_t i) {
	if (i > size())
		while (i > size())
			push_back("");
	else if (i < size()) {
		while (i < size())
			alloc.destroy(--first_free);
	}
}
#endif // !STRVEC_H