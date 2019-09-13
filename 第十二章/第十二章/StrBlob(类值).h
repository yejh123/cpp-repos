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

struct StrBlob {
	friend struct StrBlobPtr;
	friend void read(istream &in, StrBlob &sb);
	friend bool operator==(const StrBlob &, const StrBlob &);
	friend bool operator!=(const StrBlob &, const StrBlob &);
private:
	std::shared_ptr<std::vector<std::string> > data;
	void check(unsigned i, const std::string &msg) const {
		if (i >= (*this->data).size())
			throw std::out_of_range(msg);
	}
public:
	//���캯��
	StrBlob() :data(make_shared<std::vector<std::string> >()) { }
	StrBlob(initializer_list<string> il) : data(make_shared<std::vector<std::string> >(il)) { }
	//�������캯��
	StrBlob(const StrBlob &s) {
		data = make_shared<std::vector<std::string>>(*(s.data));
	}
	//�������������
	StrBlob & operator= (const StrBlob &s) {
		data = make_shared<std::vector<std::string>>(*(s.data));
		return *this;
	}
	int size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	//����Ԫ��
	void push_back(const std::string &s) {
		data->push_back(s); 		cout << "��ֵ���ð汾push_back" << endl;
	}
	void push_back(string &&s) { 
		data->push_back(std::move(s));
		cout << "��ֵ���ð汾push_back" << endl;
	}
	void pop_back() { data->pop_back(); }
	//Ԫ�ط���
	std::string& front() { return data->front(); }
	std::string& back() { return data->back(); }
	//��StrBlobPtr�Ľӿں���
	StrBlobPtr beg();
	StrBlobPtr end();

	//�±������
	std::string &operator[](std::size_t t) {
		return (*data)[t];          //����shared_ptr���±����
	}
	const std::string &operator[](std::size_t t) const {
		return (*data)[t];          //����shared_ptr���±����
	}

	//��Ա���������
	
};

void read(istream &in, StrBlob &sb)
{
	string s;
	while (getline(in, s))
	{
		(*(sb.data)).push_back(s);

	}
}

struct StrBlobPtr {
	friend struct StrBlob;
	friend void print(std::ostream &, StrBlobPtr &);
	friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
	friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
private:

	weak_ptr<vector<string>> wptr;
	size_t curr = 0;
	shared_ptr<vector<string>> check(size_t t, const string &s) const
	{
		auto sp = wptr.lock();                                 //lock����shared_ptr
		if (!sp)
			throw runtime_error("��Ч��weak_ptr");
		if (t >= sp->size())
			throw out_of_range(s);                             //ֻ��curr<size()����sp[curr]ָ��Ԫ�ز���ͨ��check
		return sp;
	}
public:
	//���캯��
	StrBlobPtr() = default;
	StrBlobPtr(StrBlob &sb, size_t t = 0) :wptr(sb.data), curr(t) {}

	//�ӿں���
	string &deref()                //����:���weakָ���Ƿ���Ч�Լ�curr�Ƿ񳬱꣬��������ָvector[curr]
	{
		auto sp = check(curr, "��������");
		return (*sp)[curr];                       //����ֱ�Ӷ�wp������
	}

	StrBlobPtr &incr()             //����:����curr
	{
		auto sp = check(curr, "��������");
		++curr;

		return *this;
	}
	//ǰ�õ����ݼ������
	StrBlobPtr &operator++() {
		check(curr, "��������");
		++curr;
		return *this;
	}
	StrBlobPtr &operator--() {
		--curr;
		check(curr, "��������");
		return *this;
	}
	//����
	StrBlobPtr operator++(int) {
		auto ret = *this;
		++*this;
		return ret;
	}
	StrBlobPtr operator--(int) {
		auto ret = *this;
		--*this;
		return ret;
	}
	//�±������
	std::string &operator[](std::size_t t) {
		auto sp = wptr.lock();
		return (*sp)[t];          //����shared_ptr���±����
	}
	const std::string &operator[](std::size_t t) const {
		auto sp = wptr.lock();
		return (*sp)[t];          //����shared_ptr���±����
	}
	//��Ա���������
	string &operator*() const {
		auto sp = check(curr,"��������");
		return (*sp)[curr];
	}
	string *operator->() const {
		return &this->operator*();
	}
	//�Ӽ��������
	StrBlobPtr &operator+(int i)
	{
		curr += i;
		return *this;
	}
	StrBlobPtr &operator-(int i) {
		curr -= i;
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
	cout << "curr=" << sbp.curr << endl;
	auto sp = sbp.wptr.lock();
	for (int i = 0; i != sp->size(); ++i)
		cout << (*sp)[i] << endl;

}
bool operator==(const StrBlob &sb1, const StrBlob &sb2) {
	return sb1.data == sb2.data;
 }
bool operator!=(const StrBlob &sb1, const StrBlob &sb2) {
	return !(sb1 == sb2);
}
bool operator==(const StrBlobPtr &sbp1, const StrBlobPtr &sbp2) {
	auto  sptr1 = sbp1.wptr.lock(), sptr2 = sbp2.wptr.lock();
//	sbp1.wptr == sbp2.wptr;          weak_ptrδ����==�����
	return sptr1 == sptr2 && sbp1.curr == sbp2.curr;

 }
bool operator!=(const StrBlobPtr &sbp1, const StrBlobPtr &sbp2) {
	return !(sbp1 == sbp2);
}

struct p {
private:
	StrBlobPtr *ptr;
public:
	p( StrBlobPtr &sbp) :ptr(&sbp) { }

	StrBlobPtr operator->() {
		return *ptr;
	}
};
#endif 