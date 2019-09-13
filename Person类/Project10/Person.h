#pragma once
#include <iostream>
#include <string>
using namespace std;
struct Person{
	friend ostream &print(ostream &, const Person &);
	friend istream &read(istream &,  Person &);
private:
	string name;
	string address;
public:
	Person() = default;
	Person(const string &n, const string &a) :name(n), address(a) {}
	Person(string n) :name(n) {}
	//Person(istream &is) { is >> *this; } ´íÎó
	const string &getName() const{ return this->name; }
	const string &getAddress() const{ return this->address; }
};
ostream &print(ostream &os, const Person &p) {
	os << p.name <<  "µÄµØÖ·:" << p.address << endl;
	return os;
}
istream &read(istream &is, Person &p) {
	is >> p.name >> p.address;
	return is;
}