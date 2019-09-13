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
	//���캯��
	Blob():data(make_shared<vector<T>>()) { }

	Blob(initializer_list<T> il):data(make_shared<vector<T>>(il)) { }
	template <typename it>Blob(it b, it e) : data(make_shared<vector<T>>(b, e)) { }
	//�ӿں���
	typename vector<T>::iterator cbegin() const      //typename�ز�����
	{
		return data->begin();
	}
	typename vector<T>::iterator cend() const        //typename�ز�����
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
	//Ԫ�ط���
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
		return (*data)[t];          //����shared_ptr���±����
	}
    //��StrBlobPtr�Ľӿں���
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


//BlobPtr��
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
		auto sp = wptr.lock();                                 //lock����shared_ptr
		if (!sp)
			throw runtime_error("��Ч��weak_ptr");
		if (t >= sp->size())
			throw out_of_range(s);                             //ֻ��curr<size()����sp[curr]ָ��Ԫ�ز���ͨ��check
		return sp;
	}
public:
	BlobPtr() = default;
	BlobPtr(const Blob<T> & bt, size_t t = 0) : wptr(bt.data), curr(t) { }
	//�ӿں���
	string &deref()                //����:���weakָ���Ƿ���Ч�Լ�curr�Ƿ񳬱꣬��������ָvector[curr]
	{
		auto sp = check(curr, "��������");
		return (*sp)[curr];                       //����ֱ�Ӷ�wp������
	}

	BlobPtr &incr()             //����:����curr
	{
		auto sp = check(curr, "��������");
		++curr;

		return *this;
	}
	BlobPtr &operator++() {
		check(curr, "��������");
		++curr;
		return *this;
	}
	BlobPtr &operator--() {
		--curr;
		check(curr, "��������");
		return *this;
	}
	//����
	BlobPtr operator++(int) {       //�β��б���int��ʾ����������Ǻ��õ�
		auto ret = *this;
		++*this;
		return ret;
	}
	BlobPtr operator--(int) {      //�β��б���int��ʾ�ݼ�������Ǻ��õ�
		auto ret = *this;
		auto ret = *this;
		--*this;
		return ret;
	}
	//�±������
	T &operator[](size_t t) {
		auto sp = wptr.lock();
		return (*sp)[t];          //����shared_ptr���±������weak_ptr���±����
	}
	const T &operator[](std::size_t t) const {
		auto sp = wptr.lock();
		return (*sp)[t];          //����shared_ptr���±����
	}
	
	//��Ա���������
	T &operator*() const {
		auto sp = check(curr, "��������");
		return (*sp)[curr];
	}
	T *operator->() const {
		return &this->operator*();        //���ص���wptr��ָvector<T>�е�Ԫ�ص�ָ��
	}
	//�Ӽ��������
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
//���� == �� !=�����
template<typename T> bool operator==(const Blob<T> &sb1, const Blob<T> &sb2) {
	return sb1.data == sb2.data;
}
template<typename T> bool operator!=(const Blob<T> &sb1, const Blob<T> &sb2) {
	return !(sb1 == sb2);
}
template<typename T> bool operator==(const BlobPtr<T> &sbp1, const BlobPtr<T> &sbp2) {
	auto  sptr1 = sbp1.wptr.lock(), sptr2 = sbp2.wptr.lock();
	//	sbp1.wptr == sbp2.wptr;          weak_ptrδ����==�����
	return sptr1 == sptr2 && sbp1.curr == sbp2.curr;

}
template<typename T> bool operator!=(const BlobPtr<T> &sbp1, const BlobPtr<T> &sbp2) {
	return !(sbp1 == sbp2);
}
