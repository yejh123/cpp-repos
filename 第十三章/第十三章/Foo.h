#pragma once
#ifndef FOO_H
#define FOO_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Foo {
private:
	vector<int> data;
public:
	Foo sorted()  &&;
	Foo sorted() const &;
	Foo(const vector<int> &vi):data(vi){ }
	void print() {
		for (auto a : data)
		cout << a << " ";
		cout << endl;
	}
};
Foo Foo::sorted() &&{
	cout<<"&&°æ±¾sorted"<<endl;
	sort(data.begin(), data.end());
	return *this;
}
Foo Foo::sorted() const & {
	cout << "const &°æ±¾sorted" << endl;
	auto f = *this;
	sort(f.data.begin(), f.data.end());
	return f;
}
#endif // !FOO_H
