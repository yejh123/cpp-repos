#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
//using namespace std;
struct Employee {
private:
	std::string name;
	int n;
	static  int num;
public:
	//构造函数
	Employee(const std::string &s): name(s),n(num++){ }
	//拷贝构造函数
	Employee(const Employee &e) {
		name = e.name;
		n = num++;
	}
	//拷贝赋值运算符
	Employee & operator=(const Employee &e) {
		name = e.name;
		return *this;
	}
	int get_n() {
		return n;
	}
	
};
//定义类静态成员
int Employee::num = 0;

#endif // !EMPLOYEE_H
