#pragma once
#ifndef STRBLOB_H
#define STRBLOB_H

#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>
#include <memory>
#include <stdexcept>
using namespace std;
class StrBlob {
private:
	std::shared_ptr<std::vector<std::string> > data;
	void check(unsigned i, const std::string &msg) const {
		if (i >= (*this->data).size())
			throw std::out_of_range(msg);
	}
public:
	//构造函数
	StrBlob() :data(make_shared<std::vector<std::string> >()) { }
	StrBlob(initializer_list<string> il) : data(make_shared<std::vector<std::string> >(il)) { }
	int size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	//增减元素
	void push_back(const std::string &s) { data->push_back(s); }
	void pop_back() { data->pop_back(); }
	//元素访问
	std::string& front() { return data->front(); }
	std::string& back() { return data->back(); }

};

#endif 