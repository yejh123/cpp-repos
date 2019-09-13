/*
定义一个Box（盒子）类，在该类定义中包括以下数据成员和成员函数。

数据成员：length（长）、width（宽）和height（高）。

成员函数：构造函数Box，设置盒子的长、宽和高3个初始数据；用函数setBox对数据成员置值；成员函数volume计算并输出盒子的体积。

函数名需与题目中所给相同。
*/
#include <iostream>
#include <string>
using namespace std;
class Box {
	double length;
	double width;
	double height;
public:
	Box(double length, double width, double height) :length(length), width(width), height(height) {}
	void setBox(double length, double width, double height) {
		this->length = length;
		this->width = width;
		this->height = height;
	}
	double volume() {
		return this->length * this->width * this->height;
	}
};
int main() {
	double d1, d2, d3;
	while (cin >> d1 >> d2 >> d3) {
		Box box(d1, d2, d3);
		cout << box.volume() << endl;
	}

}