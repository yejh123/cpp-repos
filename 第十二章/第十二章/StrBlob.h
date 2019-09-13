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
	friend struct StrBlobPtr;
	friend void read(istream &in, StrBlob &sb);
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
	//对StrBlobPtr的接口函数
	StrBlobPtr beg();
	StrBlobPtr end();

};

void read(istream &in, StrBlob &sb)
{
	string s;
	while (getline(in,s))
	{
		(*(sb.data)).push_back(s);

	}
}

struct StrBlobPtr {
	friend struct StrBlob;
	friend void print(std::ostream &, StrBlobPtr &);
private:

	weak_ptr<vector<string>> wptr;
	size_t curr = 0;
	shared_ptr<vector<string>> check(size_t t, const string &s)
	{
		auto sp = wptr.lock();
		if (!sp)
			throw runtime_error("无效的weak_ptr");
		if (t >= sp->size())
			throw out_of_range(s);
		return sp;
	}
public:
	//构造函数
	StrBlobPtr() = default;
	StrBlobPtr(StrBlob &sb, size_t t = 0) :wptr(sb.data), curr(t) {}

	//接口函数
	string &deref()                //作用:检查weak指针是否有效以及curr是否超标，并返回所指vector[curr]
	{
		auto sp = check(curr, "索引超标");
		return (*sp)[curr];                       //不能直接对wp解引用
	}

	StrBlobPtr &incr()             //作用:递增curr
	{
		auto sp = check(curr, "索引超标");
		++curr;

		return *this;
	}


};

StrBlobPtr StrBlob::beg()
{
	StrBlobPtr sbp(*this);
	return sbp;
}

StrBlobPtr StrBlob::end()
{
	StrBlobPtr sbp(*this, data->size());
	return sbp;
}

void print(ostream &out, StrBlobPtr &sbp)
{
	auto sp = sbp.wptr.lock();
	for (int i = 0; i != sp->size(); ++i)
		cout << (*sp)[i] << endl;

}
#endif 