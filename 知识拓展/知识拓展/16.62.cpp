#include<iostream>
#include <hash_map>
#include <string>
using namespace std;
struct Sales_data {
public:
	string bookNo;
	double price;
};
//第一步，打开std命名空间
namespace std {
	template<>
	struct hash<Sales_data> {
		typedef size_t rersult_type;
		typedef Sales_data augument_type;
		size_t operator() (const Sales_data& s) const;
	};
	size_t hash<Sales_data>::operator()(const Sales_data& s)const {
		return hash<string>(s.bookNo) ^ hash<double>()(s.price);
	}
}