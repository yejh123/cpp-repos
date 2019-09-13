/*
定义一个Book（图书）类，在该类定义中包括以下数据成员和成员函数。

数据成员： bookname（书名）、price（价格）和number（存书数量）。
成员函数： display()显示图书的情况；borrow()将存书数量减1，并显示当前存书数量；restore()将存书数量加1，并显示当前存书数量。
在main函数中，要求创建某一种图书对象，并对该图书进行简单的显示、借阅和归还管理。
函数名需与题目中所给相同。
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