#pragma once
#include "Quote.h"
struct Bulk_quote : public Disc_quote{

public:
	//���캯��
	Bulk_quote() = default;
	Bulk_quote(const std::string &s, double price, std::size_t n, double d) :Disc_quote(s, price, n, d) { cout << "Bulk_quote���캯��" << endl; }
	Bulk_quote(const Bulk_quote& bq) :Disc_quote(bq) { cout << "Bulk_quote�������캯��" << endl; }
	Bulk_quote( Bulk_quote&& bq) :Disc_quote(std::move(bq)) { cout << "Bulk_quote�������캯��" << endl; }
	Bulk_quote& operator=(const Bulk_quote &bq) {
		Quote::operator=(bq);
		quantity = bq.quantity;
		discount = bq.discount;
		cout << "Bulk_quote������ֵ�����" << endl;
		return *this;
	}
	Bulk_quote& operator=(Bulk_quote &&bq) {
		Quote::operator=(std::move(bq));
		quantity = std::move(bq.quantity);
		discount = std::move(bq.discount);
		cout << "Bulk_quote�ƶ���ֵ�����" << endl;
		return *this;

	}
	virtual ~Bulk_quote() { cout << "Bulk_quote��������" << endl; }
	virtual shared_ptr<Quote> clone() const{
		return shared_ptr<Quote>(new Bulk_quote(*this));
	}
	//��������
	//�����ܼ۸�
	virtual double net_price(std::size_t n) const override {
		if (n >= quantity)
			return n * (1 - discount) * price;
		else
			return n * price;
	}
	virtual void debug() const override {
		std::cout << "bookNo:" << bookNo << " " << "price:" << price << " " << "min_bug:" << quantity << " " << "discount:" << discount << std::endl;
	}
};