/*
����һ��Book��ͼ�飩�࣬�ڸ��ඨ���а����������ݳ�Ա�ͳ�Ա������

���ݳ�Ա�� bookname����������price���۸񣩺�number��������������
��Ա������ display()��ʾͼ��������borrow()������������1������ʾ��ǰ����������restore()������������1������ʾ��ǰ����������
��main�����У�Ҫ�󴴽�ĳһ��ͼ����󣬲��Ը�ͼ����м򵥵���ʾ�����ĺ͹黹����
������������Ŀ��������ͬ��
*/
#include <iostream>
#include <string>
using namespace std;
class Book {
	string BookName;
	double price;
	int number;
public:
	Book(string name, double price, int number) :BookName(name), price(price), number(number) {}
	void display() {
		cout << this->BookName << " " << this->price << " " << this->number << endl;
	}
	int borrow() {
		return --this->number;
	}
	int restore() {
		return ++this->number;
	}
	double totalPrice() {
		return this->price * this->number;
	}
};
int main() {
	string name;
	double price;
	int number;
	cin >> name >> price >> number;
	Book book(name, price, number);
	book.display();
	char c;
	while (cin >> c) {
		if (c == 'B') {
			cout << book.borrow() << endl;
		}
		else if (c == 'R') {
			cout << book.restore() << endl;
		}
		else if (c == 'C') {
			cout << book.totalPrice() << endl;
		}
	}
}