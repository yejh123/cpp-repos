#pragma once
#ifndef SALES_DATA
#define SALES_DATA
#endif
#include <string>
#include <iostream>
using namespace std;

struct Sales_data {
	friend ostream &print(ostream &os, const Sales_data &s);
	friend istream &read(istream&, Sales_data &);
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
	Sales_data(string s = "ashu") :bookNo(s) {};
	Sales_data(istream &  );
	*/

	//委托构造函数
	Sales_data(const string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(p) {}
	Sales_data(const string &s) :Sales_data(s, 0, 0) { }
	Sales_data() :Sales_data("X") {  }

	//成员函数
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&  s1) {

		units_sold += s1.units_sold;
		revenue += s1.revenue;

		return *this;
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

istream &read(istream& in, Sales_data & s) {
	in >> s.bookNo >> s.units_sold >> s.revenue;
	return in;
}

//Sales_data::Sales_data(istream &cin ) {
//	cin >> this->bookNo >> this->units_sold >> this->revenue;
//}

