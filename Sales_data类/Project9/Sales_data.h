#pragma once
#ifndef SALES_DATA
#define SALES_DATA

#include <string>
#include <iostream>
using namespace std;
struct Sales_data {
	friend ostream &print(ostream &os, const Sales_data &s);
	friend istream &read(istream &is, Sales_data &s);
	friend istream &operator>>(istream &in, Sales_data &item);
	friend ostream &operator<<(ostream &out, const Sales_data &item);
	friend Sales_data &operator+=(Sales_data &s1, const Sales_data &s2);
	friend Sales_data operator+(const Sales_data &s1, const Sales_data &s2);
private:
	//数据成员
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

public:
	/*
	//一般构造函数
	Sales_data(const string &s, unsigned n,  double p) :bookNo(s), units_sold(n), revenue(p) {}
	//Sales_data() = default;
	Sales_data(string s = "ashu") :bookNo(s) {}
	Sales_data(istream &  );
	*/

	//委托构造函数
	Sales_data(const string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(p) {  }
	Sales_data(const string &s) :Sales_data(s, 0, 0) { }
	Sales_data() = default;

	//赋值运算符
	Sales_data &operator=(const string s) {
		this->bookNo = s;
		this->units_sold = this->revenue = 0.0;
		return *this;
	}
	//成员函数
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&  s1) {

		units_sold += s1.units_sold;
		revenue += s1.revenue;

		return *this;
	}

};
class isbn_mismatch : public logic_error
{
private:
	const string left, right;
public:
	explicit isbn_mismatch(const string& s) : logic_error(s) {}
	isbn_mismatch(const string& s, const string& lhs, const string& rhs) : logic_error(s), left(lhs), right(rhs) {}
	string print() const 
	{
		string s = logic_error::what() + string(", one is ") + left + string(", the other is ") + right;
		return s.c_str();
	}
};
Sales_data add(Sales_data &s1, Sales_data &s2) {
	Sales_data sum = s1;
	sum.combine(s2);
	return sum;
}

ostream &print(ostream &os, const Sales_data &s) {
	os << s.bookNo << " " << s.units_sold << " " << s.revenue << endl;
	return os;
}

istream &read(istream &is, Sales_data &s) {
	is >> s.bookNo >> s.units_sold >> s.revenue;
	return is;
}
istream & operator>>(istream &in, Sales_data &item) {
	double price;
	in >> item.bookNo >> item.units_sold >> price;
	if (in)
		item.revenue = item.units_sold * price;
	else
		item = Sales_data();
	return in;
}
ostream &operator<<(ostream &out, const Sales_data &item) {
	out << item.bookNo << " " << item.units_sold << " " << item.revenue;
	return out;
}
Sales_data &operator+=(Sales_data &s1, const Sales_data &s2) {
	if (s1.isbn() != s2.isbn())
		throw isbn_mismatch("the isbns of two are not the same", s1.isbn(), s2.isbn());


	s1.units_sold += s2.units_sold;
	s1.revenue += s2.revenue;
	return s1;
}
Sales_data operator+(const Sales_data &s1, const Sales_data &s2) {
	Sales_data sd = s1;
	sd += s2;
	return sd;
}
//Sales_data::Sales_data(istream &cin ) {
//	cin >> this->bookNo >> this->units_sold >> this->revenue;
//}

#endif