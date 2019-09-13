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
	//���캯��
	Employee(const std::string &s): name(s),n(num++){ }
	//�������캯��
	Employee(const Employee &e) {
		name = e.name;
		n = num++;
	}
	//������ֵ�����
	Employee & operator=(const Employee &e) {
		name = e.name;
		return *this;
	}
	int get_n() {
		return n;
	}
	
};
//�����ྲ̬��Ա
int Employee::num = 0;

#endif // !EMPLOYEE_H
