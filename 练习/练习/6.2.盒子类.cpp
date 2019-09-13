/*
����һ��Box�����ӣ��࣬�ڸ��ඨ���а����������ݳ�Ա�ͳ�Ա������

���ݳ�Ա��length��������width������height���ߣ���

��Ա���������캯��Box�����ú��ӵĳ�����͸�3����ʼ���ݣ��ú���setBox�����ݳ�Ա��ֵ����Ա����volume���㲢������ӵ������

������������Ŀ��������ͬ��
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