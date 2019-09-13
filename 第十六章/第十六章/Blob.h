#pragma once
#include<iostream>
#include<algorithm>
#include<memory>
#include<string>
#include<vector>
using namespace std;
template<typename T> class BlobPtr;
template <typename T> class Blob {
	friend class BlobPtr<T>;
	friend void read(istream &in, Blob &sb);
	friend bool operator==<T>(const Blob &, const Blob &);
	friend bool operator!=<T>(const Blob &, const Blob &);
private:
	shared_ptr<vector<T>> data;
	void check(size_t i, const string &msg) const
	{
		if (i >= (*this->data).size())
			throw std::out_of_range(msg);
	}
	typedef typename vector<T>::size_type size_type;
public:
	//构造函数
	Blob():data(make_shared<vector<T>>()) { }

	Blob(initializer_list<T> il):data(make_shared<vector<T>>(il)) { }
	template <typename it>Blob(it b, it e) : data(make_shared<vector<T>>(b, e)) { }
	//接口函数
	typename vector<T>::iterator cbegin() const      //typename必不可少
	{
		return data->begin();
	}
	typename vector<T>::iterator cend() const        //typename必不可少
	{
		return data->end();
	}
	size_type size() const
	{
		return data->size();
	}
	bool empty() const
	{
		return data->empty();
	}
	void push_back(const T &t)
	{
		data->push_back(t);
	}
	void push_back(T &&t)
	{
		data->push_back(std::move(t));
	}
	void pop_back()
	{
		data->pop_back();
	}
	//元素访问
	T &front() 
	{
		return data->front();
	}
	T &back() 
	{ 
		check(0, "back on empty Blob");
		return data->back(); 
	}
	T &operator[](std::size_t t) 
	{
		return (*data)[t];          //调用shared_ptr的下标操作
	}
    //对StrBlobPtr的接口函数
	BlobPtr<T> beg();
	BlobPtr<T> end();
};
template<typename T> void read(istream &in, Blob<T> &bt)
{
	T s;
	while (getline(in, s))
	{
		(*(bt.data)).push_back(s);

	}
}


//BlobPtr类
template<typename T> 
class BlobPtr
{
	friend bool;
	friend class Blob<T>;
	friend void print(ostream &, const BlobPtr<T> &);
	friend bool operator==<T>(const BlobPtr &, const BlobPtr &);
	friend bool operator!=<T>(const BlobPtr &, const BlobPtr &);
private:
	weak_ptr<vector<T>> wptr;
	size_t curr = 0;
	shared_ptr<vector<T>> check(size_t t, const string &s) const
	{
		auto sp = wptr.lock();                                 //lock返回shared_ptr
		if (!sp)
			throw runtime_error("无效的weak_ptr");
		if (t >= sp->size())
			throw out_of_range(s);                             //只有curr<size()，即sp[curr]指向元素才能通过check
		return sp;
	}
public:
	BlobPtr() = default;
	BlobPtr(const Blob<T> & bt, size_t t = 0) : wptr(bt.data), curr(t) { }
	//接口函数
	string &deref()                //作用:检查weak指针是否有效以及curr是否超标，并返回所指vector[curr]
	{
		auto sp = check(curr, "索引超标");
		return (*sp)[curr];                       //不能直接对wp解引用
	}

	BlobPtr &incr()             //作用:递增curr
	{
		auto sp = check(curr, "索引超标");
		++curr;

		return *this;
	}
	BlobPtr &operator++() {
		check(curr, "索引超标");
		++curr;
		return *this;
	}
	BlobPtr &operator--() {
		--curr;
		check(curr, "索引超标");
		return *this;
	}
	//后置
	BlobPtr operator++(int) {       //形参列表中int表示递增运算符是后置的
		auto ret = *this;
		++*this;
		return ret;
	}
	BlobPtr operator--(int) {      //形参列表中int表示递减运算符是后置的
		auto ret = *this;
		auto ret = *this;
		--*this;
		return ret;
	}
	//下标运算符
	T &operator[](size_t t) {
		auto sp = wptr.lock();
		return (*sp)[t];          //调用shared_ptr的下标操作，weak_ptr无下标操作
	}
	const T &operator[](std::size_t t) const {
		auto sp = wptr.lock();
		return (*sp)[t];          //调用shared_ptr的下标操作
	}
	
	//成员访问运算符
	T &operator*() const {
		auto sp = check(curr, "索引超标");
		return (*sp)[curr];
	}
	T *operator->() const {
		return &this->operator*();        //返回的是wptr所指vector<T>中的元素的指针
	}
	//加减法运算符
	BlobPtr &operator+(int i)
	{
		curr += i;
		return *this;
	}
	BlobPtr &operator-(int i) {
		curr -= i;
		return *this;
	}

};

template<typename T> BlobPtr<T> Blob<T>::beg()
{
	BlobPtr sbp(*this);
	return sbp;
}

template<typename T> BlobPtr<T> Blob<T>::end()
{
    BlobPtr sbp(*this, data->size());
	return sbp;
}

template<typename T> void print(ostream &out,const BlobPtr<T> &sbp)
{
	cout << "curr=" << sbp.curr << endl;
	auto sp = sbp.wptr.lock();
	for (int i = 0; i != sp->size(); ++i)
		cout << (*sp)[i] << endl;

}
//定义 == 和 !=运算符
template<typename T> bool operator==(const Blob<T> &sb1, const Blob<T> &sb2) {
	return sb1.data == sb2.data;
}
template<typename T> bool operator!=(const Blob<T> &sb1, const Blob<T> &sb2) {
	return !(sb1 == sb2);
}
template<typename T> bool operator==(const BlobPtr<T> &sbp1, const BlobPtr<T> &sbp2) {
	auto  sptr1 = sbp1.wptr.lock(), sptr2 = sbp2.wptr.lock();
	//	sbp1.wptr == sbp2.wptr;          weak_ptr未定义==运算符
	return sptr1 == sptr2 && sbp1.curr == sbp2.curr;

}
template<typename T> bool operator!=(const BlobPtr<T> &sbp1, const BlobPtr<T> &sbp2) {
	return !(sbp1 == sbp2);
}
