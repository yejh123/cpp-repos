#pragma once
#ifndef QUOTE_H
#define QUOTE_H
#include <iostream>
#include <string>
#include <algorithm>
#include <memory>
using namespace std;
struct Quote {

protected:
	double price;
	std::string bookNo;
public:
	//构造函数
	Quote() = default;
	Quote(const std::string &s, double p) :bookNo(s), price(p) { cout << "Quote构造函数" << endl; }
	Quote(const Quote &q) :price(q.price), bookNo(q.bookNo) { cout << "Quote拷贝构造函数" << endl; }
	Quote(Quote &&q) :price(std::move(q.price)), bookNo(std::move(q.bookNo)) { cout << "Quote移动构造函数" << endl; }
	Quote& operator=(const Quote &q) {
		price = q.price;
		bookNo = q.bookNo;
		cout << "Quote拷贝赋值运算符" << endl;
		return *this;
	}
	Quote& operator=(Quote &&q) {
		price = std::move(q.price);
		bookNo = std::move(q.bookNo);
		cout << "Quote移动赋值运算符" << endl;
		return *this;
	}
	//接口函数
	std::string isbn() const { return bookNo; }
	virtual shared_ptr<Quote> clone() const{
		return shared_ptr<Quote>(new Quote (*this));
	}
	//计算总价格
	virtual double net_price(std::size_t n) const {
		return n * price;
	}
	virtual void debug() const{
		std::cout << "bookNo:" << bookNo << " " << "price:" << price << " " << std::endl;
	}
	//析构函数
	virtual ~Quote() { cout << "Quote析构函数" << endl; }
};
//打印书籍信息
double print_total(const Quote &q,std::size_t n)  {
	auto total = q.net_price(n);
	std::cout << "ISBN:" << q.isbn() << " 售出了" << n << "本" << ",共" << total << "元" << std::endl;
	return total;
}

//Disc_quote类
struct Disc_quote :public Quote {
protected:
	size_t quantity = 0;
	double discount;
public:
	Disc_quote() = default;
	Disc_quote(const std::string &name,double price,size_t quan,double dis):Quote(name,price),quantity(quan),discount(dis){ }
	virtual double net_price(size_t)const = 0;
	virtual ~Disc_quote() { cout << "Disc_quote析构函数" << endl; }
};
#endif // !QUOTE_H
