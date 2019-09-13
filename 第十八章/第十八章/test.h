#pragma once
#include <iostream>
#include <string>
using namespace std;
class test {
	int a = 0;
	double b = 0.0;
public:
	test() :a(0), b(0.0) {};
	test(int i, double d) try :a(i), b(d){}
	catch (...) {
		cerr << "error" << endl;
	}
	string toString()
	{
		string s = "test[";
		s += to_string(a) + ",";
		s += to_string(b);
		return s + "]";
	}
};
namespace {
	int i = 10;
	int f() {
		return i;
	}
}
int f2();